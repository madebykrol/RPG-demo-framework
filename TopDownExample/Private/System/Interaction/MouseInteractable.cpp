#include "TopDownExample.h"


UMouseInteractable::UMouseInteractable(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	// Default Constructor code.
}


void IMouseInteractable::OnMousePressed(AController* player, FVector pos, FKey key)
{
	// Default mouse pressed event
}

void IMouseInteractable::OnMouseReleased(AController* player, FVector pos, FKey key)
{
	// Default mouse released event
}

void IMouseInteractable::OnMouseReleased(AController* player, FVector pos, AActor * target, FKey key)
{
	// Default mouse released event
}


void IMouseInteractable::OnMouseFocusedReleased(AController* player, FVector pos, FKey key)
{
	// Default mouse released event
}

void IMouseInteractable::OnMouseHoverIn(AController* player, FVector pos)
{
	// Default mouse hover in event
}

void IMouseInteractable::OnMouseHoverOut(AController* player, FVector pos)
{
	// Default mouse hover out event
}
