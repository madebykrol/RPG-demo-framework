#pragma once
#include "TopDownExample.h"

UMouseInteractionHandler::UMouseInteractionHandler(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP){

	

};
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

bool UMouseInteractionHandler::TriggerHoverToggle(IMouseInteractable * actor, AController * player)
{
	if (CurrentHoverTarget == actor) {
		return false;
	}

	ClearHoverTarget(player);

	CurrentHoverTarget = actor;
	actor->OnMouseHoverIn(player);

	return true;
};

bool UMouseInteractionHandler::HasHoverTarget() {
	if (CurrentHoverTarget) {
		return true;
	}

	return false;
}

void UMouseInteractionHandler::ClearHoverTarget(AController * player) {
	if (CurrentHoverTarget)
	{
		CurrentHoverTarget->OnMouseHoverOut(player);
		CurrentHoverTarget = NULL;
	}
}