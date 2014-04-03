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
