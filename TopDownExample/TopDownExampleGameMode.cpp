// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "TopDownExample.h"
#include "TopDownExampleGameMode.h"
#include "TopDownExampleGameState.h"
#include "TopDownExamplePlayerController.h"

ATopDownExampleGameMode::ATopDownExampleGameMode(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	// use our custom PlayerController class
	PlayerControllerClass = ATopDownExamplePlayerController::StaticClass();
	

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FObjectFinder<UClass> PlayerPawnBPClass(TEXT("Class'/Game/Blueprints/MyCharacter.MyCharacter_C'"));

	if (PlayerPawnBPClass.Object != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Object;
	}

	HUDClass = AMyHUD::StaticClass();
	GameStateClass = ATopDownExampleGameState::StaticClass();

	// Setup inventory

	// Finished quests.
}


void ATopDownExampleGameMode::OnPlayerDied(AController * player)
{
	
}

void ATopDownExampleGameMode::ResurrectPlayer(AController * player)
{

}


