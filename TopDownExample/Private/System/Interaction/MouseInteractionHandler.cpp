#pragma once
#include "TopDownExample.h"

UMouseInteractionHandler::UMouseInteractionHandler(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP){

	

};

IMouseInteractable * UMouseInteractionHandler::GetCurrentPressTarget() {
	return CurrentPressTarget;
}

bool UMouseInteractionHandler::IsInteractable(AActor * actor)
{
	IMouseInteractable * object = InterfaceCast<IMouseInteractable>(actor);

	if (object) {
		return true;
	}
	return false;
};

IMouseInteractable * UMouseInteractionHandler::GetInteractableObject(AActor * actor) 
{
	// We fire another trace to figure out if there is something in the way between us and the Actor.
	IMouseInteractable * object = InterfaceCast<IMouseInteractable>(actor);

	if (object) {
		return object;
	}
	else {
		return NULL;
	}
};

void UMouseInteractionHandler::TriggerHoverToggle(IMouseInteractable * actor, AController * player, FVector pos)
{
	if (CurrentHoverTarget == actor) {
		return;
	}

	ClearHoverTarget(player, pos);

	CurrentHoverTarget = actor;
	actor->OnMouseHoverIn(player, pos);
};



void UMouseInteractionHandler::TriggerMousePress(IMouseInteractable * actor, AController * player, FVector pos) 
{
	CurrentPressTarget = actor;
	actor->OnMousePressed(player, pos);
}

void UMouseInteractionHandler::TriggerMouseRelease(AController * player, FVector pos, bool focus)
{
	if (CurrentPressTarget) {
		if (focus) {
			CurrentPressTarget->OnMouseFocusedReleased(player, pos);
		}
		else {
			CurrentPressTarget->OnMouseReleased(player, pos);
		}
		
		CurrentPressTarget = nullptr;
	}
}


void UMouseInteractionHandler::TriggerMouseRelease(AController * player, FVector pos, AActor * target) {
	if (CurrentPressTarget) {

		CurrentPressTarget->OnMouseReleased(player, pos, target);

		CurrentPressTarget = nullptr;
	}
}

bool UMouseInteractionHandler::HasHoverTarget() {
	if (CurrentHoverTarget) {
		return true;
	}

	return false;
}

void UMouseInteractionHandler::ClearHoverTarget(AController * player, FVector pos) {
	if (CurrentHoverTarget)
	{
		CurrentHoverTarget->OnMouseHoverOut(player, pos);
		CurrentHoverTarget = NULL;
	}
}