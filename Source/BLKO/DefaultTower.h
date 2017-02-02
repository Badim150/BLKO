// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DefaultTower.generated.h"

UCLASS(Blueprintable)
class BLKO_API ADefaultTower : public AActor
{
	GENERATED_BODY()

public:
	//Cost property
	//The cost of building the tower
	//Value is updated on Tower Upgrade and 50% of this value is returned to the player if the tower is sold
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultTower")
		float Cost = 10;

	//UpgradeCost property
	//The cost of Upgrading the tower
	//This value is 150% of the tower's current Cost
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultTower")
		float UpgradeCost = 15;

	//UpgradeValue property
	//The multiplier on which the tower's values are increased on upgrade
	//The base value is 150%
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultTower")
		float UpgradeValue = 1.1;

	//Damage property
	//The ammount of damage one tower shot does
	//This value is increased on Tower Upgrade
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultTower")
		float Damage = 10;

	//AttackSpeed property
	//The number of times per second that the tower attacks
	//This value is increased on Tower Upgrade
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultTower")
		float AttackSpeed = 1;

	//Range property
	//How far can the tower target and shoot and enemy
	//This value is increased on Tower Upgrade
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultTower")
		float Range = 400;

	//FireCooldown property
	//How long until the tower can fire again after shooting
	//This value is obtained using the CurrentGameTime and the AttackSpeed values
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultTower")
		float FireCooldown = 1;

	//TargetEnemy property
	//The tower's target actor
	//When a new enemy enters the tower's range a reference to it is stored here
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultTower")
		AActor* TargetEnemy;

	//SphereCollision property
	//The tower's HitBox
	//This sphere collision is effectively the Tower's attack range
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultTower")
	//	UDrawSphereComponent::USphereComponent*  SphereCollision;

	//Sell function
	//Function that calculates the tower's refund cost and destroys it
	//Sets the Tower's lifespan to 2seconds and returns the refund cost
	UFUNCTION(BlueprintCallable, Category = "DefaultTower")
		virtual float SellTower();
	
	//UpgradeTower function
	//Function that upgrades the tower's Damage, Attack Speed and Range.
	//It also updates the Cost and UpgradeCost
	UFUNCTION(BlueprintCallable, Category = "DefaultTower")
		virtual void UpgradeTower();

	//UpdateTowerRange function
	//Function that updates the tower's SphereCollision Radius based on the tower's range

	UFUNCTION(BlueprintCallable, Category = "DefaultTower")
		void UpdateTowerRange(AActor* c);

	//UpdateCooldown function
	//Fuction that calculates when the tower can shoot again based on the tower's attackSpeed value.
	UFUNCTION(BlueprintCallable, Category = "DefaultTower")
		void UpdateCooldown();

	//LockOn function
	//Fuction that stores the tower's new target enemy, unless it already is targeting an enemy
	UFUNCTION(BlueprintCallable, Category = "DefaultTower")
		void LockOn(AActor* Target);

	//LockOff function
	//Fuction called when the target enemy is no longer in range or is dead
	//Clears TargetEnemy
	UFUNCTION(BlueprintCallable, Category = "DefaultTower")
		void LockOff(AActor* Target);

	//DealDamage function
	//Receives a target and applies Damage to it
	UFUNCTION(BlueprintCallable, Category = "DefaultTower")
		void DealDamage();

	//Editor code to make updating values in the editor cleaner
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
public:	
	// Sets default values for this actor's properties
	ADefaultTower();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
