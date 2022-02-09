
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatusComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class Z_1223_API UCStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCStatusComponent();

	bool CanMove();
	bool IsAlive(); 
	bool IsActive();

	void SetMove();
	void SetStop();
	void SetAlive();
	void SetDead();
	void SetActive();
	void SetInActive();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Speed")
		float WalkSpeed = 200.0f;
	bool bCanMove = true;
	bool bAlive = true;
	bool bActive = true;
};
