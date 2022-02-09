// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUserWidget_ChangeScene.generated.h"

/**
 * 
 */
UCLASS()
class Z_1223_API UCUserWidget_ChangeScene : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void Click();
	
};
