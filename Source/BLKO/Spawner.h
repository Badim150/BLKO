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

	//TimeToSpawn property
	//A float that has the time in game seconds until the spawner can spawn another enemy
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		float TimeToSpawn;

	//WaveString property
	//Stores the waves
	FString WaveString;

	//NextWave property
	//A string of int that corresponds to the enemies that will be spawned next.
	FString NextWave;

	//EnemyToSpawn property
	//FString that has the type of enemy to spawn next
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		FString EnemyToSpawn;

	//TimeWave property
	//Float with the seconds between waves
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		float TimeWave = 10;

	//TimeMob property
	//Float with the seconds between waves
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		float TimeMob = 0.5;
	 
	//TimeBoss property
	//Float with the seconds between boss waves
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		float TimeBoss = 15;

	//Enabled property
	//Boolean that controls if the spawner is active or not
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner")
		bool Enabled = false;

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
		void GetWaveFromFile();

	//EnableSpawner function
	//Function that enables a disabled spawner and updates its waveNumber
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void EnableSpawner(int wave);

	//DisableSpawner function
	//Function that disables the spawner 
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void DisableSpawner();


	//HardMode function
	//Function that disables and enabled spawner
	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void HardMode(int wave);

	

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