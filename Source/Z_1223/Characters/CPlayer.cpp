
#include "CPlayer.h"
#include "Global.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "Components/CStatusComponent.h"

#include "Materials/MaterialInstanceConstant.h"
//#include "Components/CMontagesComponent.h"
#include "CPlatformer.h"
#include "MyGameModeBase.h"
#include "Widgets/CUserWidget_ChangeScene.h"

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateComponent<USpringArmComponent>(this, &SpringArm, "SpringArm", GetMesh());
	CHelpers::CreateComponent<UCameraComponent>(this, &Camera, "Camera", SpringArm);

	CHelpers::CreateActorComponent<UCStatusComponent>(this, &Status, "Status");

	//CHelpers::GetClass<UCUserWidget_ChangeScene>(&ChangeSceneClass, "WidgetBlueprint'/Game/UI/WB_SceneButton.WB_SceneButton_C'");

	//CHelpers::CreateActorComponent<UCMontagesComponent>(this, &Montages, "Montages");
	//CHelpers::CreateActorComponent<UCActionComponent>(this, &Action, "Action");

	bUseControllerRotationYaw = false;

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	TSubclassOf<UAnimInstance> animInstance;
	CHelpers::GetClass<UAnimInstance>(&animInstance, "AnimBlueprint'/Game/BluePrints/Player/ABP_CPlayer.ABP_CPlayer_C'");
	GetMesh()->SetAnimInstanceClass(animInstance);

	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bEnableCameraLag = true;

	GetCharacterMovement()->RotationRate = FRotator(0, 720, 0);
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay(); // we call default begin play from Super class
						// But for what? Default Begin Play Function contains
						// Some methods, that are neccessarry to execute it as
						// actually BeginPlay function. but when we override it,
						// all the functionality of default BeginPlay disappears.
						// Because of overriding, we need at first to call default
						// BeginPlay function, to include default function logic,
						// and then do the rest of things.

	//ChangeScene = CreateWidget<UCUserWidget_ChangeScene, APlayerController>
	//	(GetController<APlayerController>(), ChangeSceneClass);
	//ChangeScene->AddToViewport();
	//ChangeScene->SetVisibility(ESlateVisibility::Visible);
	
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	CheckFalse(Status->IsActive());

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer::OnMoveRight);

	PlayerInputComponent->BindAction("ChangeScene", EInputEvent::IE_Pressed,
		this, &ACPlayer::OnChangeScene);
}

void ACPlayer::OnMoveForward(float InAxis)
{
	CheckFalse(Status->CanMove());

	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetForwardVector();
	AddMovementInput(direction, InAxis);
}

void ACPlayer::OnMoveRight(float InAxis)
{
	CheckFalse(Status->CanMove());

	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetRightVector();
	AddMovementInput(direction, InAxis);
}

void ACPlayer::OnChangeScene()
{
//	CHelpers::GetClass<AMyGameModeBase>(&DefaultPawnClass, "Blueprint'/Game/BluePrints/Player/BP_CPlayer.BP_CPlayer_C'");

	//GetController<APlayerController>()->SetInputMode(FInputModeGameAndUI());
}

