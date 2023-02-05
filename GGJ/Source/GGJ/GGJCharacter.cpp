#include "GGJCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/GrowComponent.h"
#include "Controllers/GGJPlayerController.h"
#include "GGJ/GrowSpot.h"
#include "GGJ/GrowPatch.h"
#include "Interfaces/VegetableInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Animation/AnimMontage.h"
#include "GGJ/Widgets/Widget_PauseMenu.h"

AGGJCharacter::AGGJCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 300.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 4000.f;
	
}

void AGGJCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), this->PlayerIndex))//Cast<APlayerController>(Controller))
	{

		controller->bShowMouseCursor = true;
		controller->SetInputMode(FInputModeGameAndUI{});
		
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(controller->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	else
	{
		UKismetSystemLibrary::PrintString(GetWorld(), "No Player Controller");
	}

	SpawnPlayerPatch();
}

void AGGJCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AGGJCharacter::TryHarvest()
{
	if (PlayerPatch && !CurrentVegetable)
	{
		CurrentVegetable = PlayerPatch->HarvestClosestGridPosition(GetActorLocation());
		if (CurrentVegetable)
		{
			if (UGrowComponent* growComponent = Cast<UGrowComponent>(CurrentVegetable->GetComponentByClass(UGrowComponent::StaticClass())))
			{
				UE_LOG(LogTemp, Warning, TEXT("Stop Vegetable Growing!"));
				growComponent->IsGrowing = false;
			}
			CurrentVegetable->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("VegetableTarget"));

			if (IVegetableInterface* vegetable = Cast<IVegetableInterface>(CurrentVegetable))
			{
				vegetable->Harvest();
				if (PickupAnim)
				{
					GetMesh()->GetAnimInstance()->Montage_Play(PickupAnim, 3);
				}
			}
		}
	}
	else if (CurrentVegetable)
	{
		if (IVegetableInterface* vegetable = Cast<IVegetableInterface>(CurrentVegetable))
		{
			vegetable->Throw(GetActorForwardVector() + GetActorUpVector());
			CurrentVegetable->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			CurrentVegetable->SetLifeSpan(3.0f);
			CurrentVegetable = nullptr;
			
			if (ThrowAnim)
			{
				GetMesh()->GetAnimInstance()->Montage_Play(ThrowAnim, 3);
			}
		}
	}

}

void AGGJCharacter::Pause()
{
	if (AGGJPlayerController* controlller = Cast<AGGJPlayerController>(Controller))
	{
		if (!PauseMenuWidget)
		{
			PauseMenuWidget = CreateWidget<UWidget_PauseMenu>(controlller, PauseMenuPrefab);
			PauseMenuWidget->AddToViewport();
			controlller->bShowMouseCursor = true;
			controlller->SetInputMode(FInputModeGameAndUI{});
			controlller->bEnableClickEvents = true;
			PauseMenuWidget->Initialize();
			PauseMenuWidget->Resume_Button->OnPressed.AddDynamic(this, &AGGJCharacter::Pause);
		}
		else
		{
			PauseMenuWidget->RemoveFromParent();
			PauseMenuWidget = nullptr;
			controlller->bShowMouseCursor = false;
			controlller->SetInputMode(FInputModeGameOnly{});
		}
	}
}

void AGGJCharacter::SpawnPlayerPatch()
{
	TArray<AActor*> ActorsToFind;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGrowPatch::StaticClass(), ActorsToFind);
	if (ActorsToFind.Num() > 0)
	{
		PlayerPatch = Cast<AGrowPatch>(ActorsToFind[0]);
	}
	/*else if (PlayerPatch == nullptr)
	{
		PlayerPatch = GetWorld()->SpawnActor<AGrowPatch>(GrowPatchPrefab, {GetActorLocation().X, GetActorLocation().Y, 0}, FRotator(FQuat::Identity));		
	}*/
}

void AGGJCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGGJCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGGJCharacter::Look);
		EnhancedInputComponent->BindAction(HarvestAction, ETriggerEvent::Triggered, this, &AGGJCharacter::TryHarvest);
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Triggered, this, &AGGJCharacter::Pause);
	}
}

void AGGJCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AGGJCharacter::Look(const FInputActionValue& Value)
{
}



