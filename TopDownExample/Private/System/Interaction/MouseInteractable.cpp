#pragma once
#include "TopDownExample.h"


UMouseInteractable::UMouseInteractable(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	// Default Constructor code.
}


void IMouseInteractable::OnMousePressed(AController* user)
{
	// Default mouse pressed event
}

void IMouseInteractable::OnMouseReleased(AController* user)
{
	// Default mouse released event
}

void IMouseInteractable::OnMouseHoverIn(AController* user)
{
	// Default mouse hover in event
}

void IMouseInteractable::OnMouseHoverOut(AController* user)
{
	// Default mouse hover out event
}