// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "DefaultEnemy.generated.h"


// Make class Blueprintable (acessible through UE4): UCLASS() -> UCLASS(Blueprintable)

	UCLASS(Blueprintable)
	class BLKO_API ADefaultEnemy : public ACharacter
	{
		GENERATED_BODY()

	public:

		//Health property
		//Current Health of the enemy
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultEnemy")
			float Health = 10;

		//MaxHealth property
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultEnemy")
			float MaxHealth = 10;

		//Worth property
		//How much gold does it award on death
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultEnemy")
			float Worth = 15;

		//Damage property
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultEnemy")
			float Damage = 1;

		//MovementSpeed property
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultEnemy")
			float MovementSpeed = 100;

		//isDead property
		UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "DefaultEnemy")
			bool isDead = false;

		//Goal
		//A vector3 to store the location of the Finish Line
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DefaultEnemy")
			AActor *Goal;

	
		//Calculate Dead function
		//Checks if the chartacter is dead
		virtual void CalculateDead(AActor* c);

		//DealDamage function
		//Updates Health when damage is taken (or healing..)
		UFUNCTION(BlueprintCallable, Category = "DefaultEnemy")
			virtual void DealDamage(float delta);

		//Upgrade Enemy function
		//Makes enemies stronger with each round
		UFUNCTION(BlueprintCallable, Category = "DefaultEnemy")
			virtual void UpgradeEnemy(int roundNumber);


		//Editor code to make updating values in the editor cleaner
#if WITH_EDITOR
		virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif


public:
	// Sets default values for this character's properties
	ADefaultEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
