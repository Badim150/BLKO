// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <random>
#include <string>
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"





UCLASS(Blueprintable)
class BLKO_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:
	//Wave Number property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		int WaveNumber = 0;

	//TimeUntilNextWave property
	//Float that will be the current game time summed with a float, to calculate when the next wave should spawn
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		float TimeUntilNextWave = -1;

	//NextWave
	//A string of int that corresponds to the enemies that will be spawned next.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		FString NextWave;


	//PlanWave function
	//Function that will plan the next wave and store it
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void PlanWave();

	//CreateWave function
	//Auxiliary function for the PlanWave function that receives all parameters and returns a wave string
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void CreateWave(int enemyNumber, int difficulty);

	//SpawnEnemy
	//Function that returns an int corresponding to the next enemy to be spawned
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		int SpawnEnemy();

	//RushWave
	//Function that adds the next wave of enemies to the current one
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void RushWave();

	//Wave Strings
	//Non-random strings to use on the first waves
	std::string WaveString[10] = { 
		"111111111",				//wave 1 - 5  easy enemies
		"1111111111",			//wave 2 - 10 easy enemies
		"111111111111111",		//wave 3 - 15 easy enemies
		"22222",				//wave 4 - 5  normal enemies
		"2222222222",			//wave 5 - 10 normal enemies
		"121212121212121",		//wave 6 - 15 easy and normal enemies
		"3231323132",				//wave 7 - 5  flying enemies
		"12121212121212121212", //wave 8 - 10 easy enemies
		"3333333333",			//wave 9 - 10 flying enemies
		"1111111111111111111111111111111111111111111111111111111"						//wave 10 - boss 
	};

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif


public:	
	// Sets default values for this actor's properties
	ASpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};