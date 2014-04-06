#pragma once
#include "TopDownExample.h"


UMouseInteractable::UMouseInteractable(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	// Default Constructor code.
}


void IMouseInteractable::OnMousePressed(AController* player)
{
	// Default mouse pressed event
}

void IMouseInteractable::OnMouseReleased(AController* player)
{
	// Default mouse released event
}

void IMouseInteractable::OnMouseHoverIn(AController* player)
{
	// Default mouse hover in event
}

void IMouseInteractable::OnMouseHoverOut(AController* player)
{
	// Default mouse hover out event
}