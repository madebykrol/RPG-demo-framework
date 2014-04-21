#pragma once

#include "SpellProjectile.generated.h"
UCLASS()
class ASpellProjectile : public AActor {
	GENERATED_UCLASS_BODY()

	/** initial setup */
	virtual void PostInitializeComponents() OVERRIDE;

	/** movement component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	TSubobjectPtr<UProjectileMovementComponent> MovementComp;

	/** collisions */
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	TSubobjectPtr<USphereComponent> CollisionComp;

	UPROPERTY(EditAnywhere, Category = Projectile)
	AActor* ProjectileActor;

	/** controller that fired me (cache for damage calculations) */
	TWeakObjectPtr<AController> MyController;

protected : 
	USpell * CurrentSpell;
public :
	void SetSpell(USpell * spell);

	/** handle hit */
	UFUNCTION()
	void OnImpact(const FHitResult& HitResult);

	void Explode();

	void DisableAndDestroy();
};
