// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "TopDownExample.h"


ABasicNPC::ABasicNPC(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void ABasicNPC::OnMouseReleased(AController* user) 
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Released"));
}

void ABasicNPC::OnMouseHoverIn(AController * player)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Hover in on NPC"));
}

void ABasicNPC::OnMouseHoverOut(AController * player)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Hover out from NPC"));
}

void ABasicNPC::OnMousePressed(AController * player)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Pressed"));
}


void ABasicNPC::OnTakeDmg() 
{

}


