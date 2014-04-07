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

bool UMouseInteractionHandler::TriggerHoverToggle(IMouseInteractable * actor, AController * player, FVector pos)
{
	if (CurrentHoverTarget == actor) {
		return false;
	}

	ClearHoverTarget(player, pos);

	CurrentHoverTarget = actor;
	actor->OnMouseHoverIn(player, pos);

	return true;
};



bool UMouseInteractionHandler::TriggerMousePress(IMouseInteractable * actor, AController * player, FVector pos) 
{
	CurrentPressTarget = actor;
	actor->OnMousePressed(player, pos);
	return false;
}

bool UMouseInteractionHandler::TriggerMouseRelease(AController * player, FVector pos, bool focus)
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
	return false;
}


bool UMouseInteractionHandler::TriggerMouseRelease(AController * player, FVector pos, bool focus, IMouseInteractable * target) {
	if (CurrentPressTarget) {
		if (focus) {
			CurrentPressTarget->OnMouseFocusedReleased(player, pos);
		}
		else {
			CurrentPressTarget->OnMouseReleased(player, pos);
		}

		CurrentPressTarget = nullptr;
	}
	return false;
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