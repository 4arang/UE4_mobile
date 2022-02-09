
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"


UCLASS()
class Z_1223_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float Speed;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float Direction;

public:
	virtual void NativeBeginPlay() override; //Executed when begin play is called on the owning component
	virtual void NativeUpdateAnimation(float DeltaSeconds) override; //to simply gather data in this step and for the bulk of the work to be done 
};
