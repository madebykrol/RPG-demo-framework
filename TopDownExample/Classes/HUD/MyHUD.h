// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"


/**
 * 
 */
UCLASS()
class AMyHUD : public AHUD
{
	GENERATED_UCLASS_BODY()
	
	TSharedPtr<class SGameWidget> GameWidget;
	void BeginPlay();
	void DrawWidget();
};
