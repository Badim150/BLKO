// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DefaultEnemy.h"
#include "GameFramework/Actor.h"
#include "DefaultProjectile.generated.h"



UCLASS(Blueprintable)
class BLKO_API ADefaultProjectile : public AActor
{
	GENERATED_BODY()

public:
	//Damage property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultProjectile")
		float Damage = 1;

	//Target property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultProjectile")
		ADefaultEnemy *Target;


	//Deal Damage function
	//The projectile deals damage to the target
	UFUNCTION(BlueprintCallable, Category = "DefaultProjectile")
		virtual void DealDamage();

	//Update Damage function
	//Called on creation to update the projectile damage based on the tower that spawned it
	UFUNCTION(BlueprintCallable, Category = "DefaultProjectile")
		virtual void InitProjectile(float dmg, ADefaultEnemy *tar);

	//Update Target function
	//Called on update to check if the target is still valid
	//In case it's not, the projectile kills itself
	UFUNCTION(BlueprintCallable, Category = "DefaultProjectile")
		virtual void UpdateTarget();



		//Editor code to make updating values in the editor cleaner
#if WITH_EDITOR
		virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
public:	
	// Sets default values for this actor's properties
	ADefaultProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
