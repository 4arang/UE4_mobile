#include "CStatusComponent.h"
#include "Global.h"

UCStatusComponent::UCStatusComponent()
{

}

void UCStatusComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UCStatusComponent::CanMove()
{
	return bCanMove;
}

bool UCStatusComponent::IsAlive()
{
	return bAlive;
}

bool UCStatusComponent::IsActive()
{
	return bActive;
}

void UCStatusComponent::SetMove()
{
	bCanMove = true;
}

void UCStatusComponent::SetStop()
{
	bCanMove = false;
}

void UCStatusComponent::SetAlive()
{
	bAlive = true;
}

void UCStatusComponent::SetDead()
{
	bAlive = false;
}

void UCStatusComponent::SetActive()
{
	bActive = true;
}

void UCStatusComponent::SetInActive()
{
	bActive = false;
}


