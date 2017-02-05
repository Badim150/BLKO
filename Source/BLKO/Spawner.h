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

	//NextWave property
	//A string of int that corresponds to the enemies that will be spawned next.	

	FString NextWave;

	//TimeToSpawn property
	//A float that has the time in game seconds until the spawner can spawn another enemy
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		float TimeToSpawn;

	//Wave Strings
	//Stores the waves
	FString WaveString;

	//EnemyToSpawn property
	//FString that has the type of enemy to spawn next
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		FString EnemyToSpawn;

	//TimeWave
	//Float with the seconds between waves
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		float TimeWave = 8;

	//TimeMob
	//Float with the seconds between waves
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		float TimeMob = 0.2;

	//TimeBoss
	//Float with the seconds between boss waves
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		float TimeBoss = 12;


	//PlanWave function
	//Function that will plan the next wave and store it
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void PlanWave(AActor* c, float t);

	//CreateWave function
	//Auxiliary function for the PlanWave function that receives all parameters and returns a wave string
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void CreateWave(int enemyNumber, int difficulty);

	//SpawnEnemy function
	//Function that returns an int corresponding to the next enemy to be spawned
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void SpawnEnemy(AActor* c);

	//RushWave function
	//Function that adds the next wave of enemies to the current one
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void RushWave();

	//UpdateSpawnTime function
	//Function that times the cooldown between spawns
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void UpdateSpawnTime(float tm);

	//GetWaveFromFile function
	//Function that loads the waves from an outside file
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void getWaveFromFile();
	

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