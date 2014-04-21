#include "TopDownExample.h"
#include "TopDownExampleGameState.h"

ATopDownExampleGameState::ATopDownExampleGameState(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	PlayerInventory = NewObject<UPlayerInventory>(this);


}

void ATopDownExampleGameState::OnPlayerDied(ACharacter * player, AActor* attacker)
{

}

void ATopDownExampleGameState::OnGameStart()
{

}

void ATopDownExampleGameState::SpawnProjectile()
{

}