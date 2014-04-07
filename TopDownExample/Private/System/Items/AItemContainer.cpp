// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "TopDownExample.h"


AAItemContainer::AAItemContainer(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}


void AAItemContainer::OnOpen(AController * user)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Open chest"));
	}
}

void AAItemContainer::OnMousePressed(AController* user, FVector pos)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Pressed"));
	}
}

void AAItemContainer::OnMouseFocusedReleased(AController* user, FVector pos)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Released"));
	}
}

void AAItemContainer::OnMouseReleased(AController* user, FVector pos)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Released"));
	}
}

void AAItemContainer::OnMouseReleased(AController* user, FVector pos, IMouseInteractable * target)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Released"));
	}
}

void AAItemContainer::OnMouseHoverIn(AController* user, FVector pos)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Hover In"));
	}
}

void AAItemContainer::OnMouseHoverOut(AController* user, FVector pos)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Hoover Out"));
	}
}
