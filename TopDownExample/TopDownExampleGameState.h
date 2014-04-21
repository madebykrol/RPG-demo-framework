
#include "TopDownExampleGameState.generated.h"

UCLASS()
class ATopDownExampleGameState : public AGameState
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	UPlayerInventory * PlayerInventory;


	UFUNCTION()
	void OnPlayerDied(ACharacter * player, AActor* attacker);

	void OnGameStart();

	void SpawnProjectile();
};