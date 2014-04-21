// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "TopDownExampleGameMode.generated.h"

UCLASS(minimalapi)
class ATopDownExampleGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()



	void GameOver();
	void StartGame();

	void OnPlayerDied(AController * player);
	void ResurrectPlayer(AController * player);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerDiedEvent(AController * player);

	UFUNCTION(BlueprintImplementableEvent)
	void OnResurrectPlayerEvent(AController * player);
};


