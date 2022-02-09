// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlatformer.generated.h"

UCLASS()
class Z_1223_API ACPlatformer : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlatformer();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent* Camera;
	UPROPERTY(VisibleDefaultsOnly)
		class UCStatusComponent* Status;

	class UMaterialInstanceDynamic* BodyMaterial;

	void OnMoveRight(float InAxis);
	void OnJump();
};
