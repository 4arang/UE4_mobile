

#include "Characters/CPlatformer.h"
#include "Global.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "Components/CStatusComponent.h"

#include "Materials/MaterialInstanceConstant.h"

ACPlatformer::ACPlatformer()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateComponent<USpringArmComponent>(this, &SpringArm, "SpringArm", GetMesh());
	CHelpers::CreateComponent<UCameraComponent>(this, &Camera, "Camera", SpringArm);
	CHelpers::CreateActorComponent<UCStatusComponent>(this, &Status, "Status");

	//CHelpers::CreateActorComponent<UCMontagesComponent>(this, &Montages, "Montages");
	//CHelpers::CreateActorComponent<UCActionComponent>(this, &Action, "Action");
	
	bUseControllerRotationYaw = false;

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	TSubclassOf<UAnimInstance> animInstance;
	CHelpers::GetClass<UAnimInstance>(&animInstance, "AnimBlueprint'/Game/BluePrints/Platformer/ABP_CPlatformer.ABP_CPlatformer_C'");
	GetMesh()->SetAnimInstanceClass(animInstance);

	SpringArm->TargetArmLength = 1200.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bEnableCameraLag = true;

	GetCharacterMovement()->RotationRate = FRotator(0, 720, 0);
	GetCharacterMovement()->bOrientRotationToMovement = true;

}
void ACPlatformer::BeginPlay()
{
	Super::BeginPlay();
	
	//Status->SetInActive();
	//Status->SetStop();
}

void ACPlatformer::OnMoveRight(float InAxis)
{
	CheckFalse(Status->CanMove());

	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetRightVector();
	AddMovementInput(direction, InAxis);
}

void ACPlatformer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ACPlatformer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlatformer::OnMoveRight);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACPlatformer::OnJump);
}

void ACPlatformer::OnJump()
{
	

}
