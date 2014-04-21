#pragma once

#include "Spell.generated.h"
UCLASS()
class USpell : public UObject {
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	TSubclassOf<class ASpellProjectile> SpellprojectileClass;

	bool bExplodesOnImpact;
	bool bIsAOE;
	float BlastRadius;
	float ProjectileDecay;
	

public : 
	bool IsAOE();
	bool ExplodesOnImpact();

	float GetBlastRadius();
	int GetBlastDamage(float distanceToImpactPoint);

	float GetProjectileDecay();

	void SetSpellProjectileClass(TSubclassOf<class ASpellProjectile> projectileClass);
	TSubclassOf<class ASpellProjectile> GetSpellProjectileClass();
};

