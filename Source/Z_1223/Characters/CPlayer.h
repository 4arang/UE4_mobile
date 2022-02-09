
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlayer.generated.h"

UCLASS()
class Z_1223_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlayer();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//Allows a Pawn to set up custom input bindings.Called upon possession by a PlayerController, using the InputComponent created by CreatePlayerInputComponent()


protected:
	virtual void BeginPlay() override; //Overridable native event for when play begins for this actor
	UPROPERTY(BlueprintReadOnly)
		class AMyGameModeBase* MyGameModeBase;


private:
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent* Camera;
	UPROPERTY(VisibleDefaultsOnly)
		class UCStatusComponent* Status;
	UPROPERTY(VisibleDefaultsOnly)
		TSubclassOf<class UCUserWidget_ChangeScene> ChangeSceneClass;

	//UPROPERTY(VisibleDefaultsOnly)
	//	class UCMontagesComponent* Montages;
	class UMaterialInstanceDynamic* BodyMaterial;
	class UCUserWidget_ChangeScene* ChangeScene;

	void OnMoveForward(float InAxis);
	void OnMoveRight(float InAxis);
	void OnChangeScene();
};
