// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "TopDownExample.h"


ABasicNPC::ABasicNPC(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void ABasicNPC::OnMouseReleased(AController* user, FVector pos, FKey key)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Released"));
}

void ABasicNPC::OnMouseReleased(AController* user, FVector pos, AActor * target, FKey key)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Released on target"));
}

void ABasicNPC::OnMouseFocusedReleased(AController* user, FVector pos, FKey key)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Released"));
}

void ABasicNPC::OnMouseHoverIn(AController * player, FVector pos)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Hover in on NPC"));
}

void ABasicNPC::OnMouseHoverOut(AController * player, FVector pos)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Hover out from NPC"));
}

void ABasicNPC::OnMousePressed(AController * player, FVector pos, FKey key)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Pressed"));
}

void ABasicNPC::OnTakeDmg()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Take dmg"));
}

void ABasicNPC::OnDealDmg()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Deal dmg"));
}

void ABasicNPC::OnDeath()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Died"));
}

void ABasicNPC::OnResurrect()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Resurrected"));
}

void ABasicNPC::AddEnergy(int value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Add Energy"));
}


void ABasicNPC::AddHealth(int value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Add Health"));
}

void ABasicNPC::AddMana(int value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Add Mana"));
}

// Subtraction of status
void ABasicNPC::SubtractHealth(int value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Subtract Health"));
}

void ABasicNPC::SubtractEnergy(int value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Subtract Energy"));
}

void ABasicNPC::SubtractMana(int value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Subtract Mana"));
}

int ABasicNPC::GetCurrentEnergy()
{
	return 0;
}

int ABasicNPC::GetCurrentHealth()
{
	return 0;
}

int ABasicNPC::GetCurrentMana()
{
	return 0;
}

int ABasicNPC::GetMaxHealth()
{
	return 0;
}

int ABasicNPC::GetMaxEnergy()
{
	return 0;
}

int ABasicNPC::GetMaxMana()
{
	return 0;
}

void ABasicNPC::ReceiveActorBeginOverlap(AActor* Other)
{
	Super::ReceiveActorBeginOverlap(Other);

	Execute_OnActorBeginOverlapEvent(this, Other);
}