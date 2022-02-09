// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "Global.h"

AMyGameModeBase::AMyGameModeBase()
{
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/BluePrints/Player/BP_CPlayer.BP_CPlayer_C'");
}