// Fill out your copyright notice in the Description page of Project Settings.

#include "BLKO.h"
#include "Spawner.h"
#include <random>
#include <string>



// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


//Implement the PlanWave function.
void ASpawner::PlanWave()
{
	//	FString NextWave(WaveString[(WaveNumber - 1)].c_str());

		NextWave = WaveString[(WaveNumber - 1)].c_str();
}

//Implement the CreateWave function.
//EnemyNumer is the number of enemies that will spawn this wave: 10-30
//Difficulty is how hard the wave is: 1-3 or 4 for Boss
void ASpawner::CreateWave(int EnemyNumber, int Difficulty)
{/*
	int min, max;

	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

	auto random_integer = uni(rng);
	*/
	//Deprecated, to use if I decide to implement random waves after boss
}

//Implement the SpawnEnemy function.
int ASpawner::SpawnEnemy()
{
	//implemented with blueprint
	return -1;
}

//Implement the RushWave function.
void ASpawner::RushWave()
{}


#if WITH_EDITOR
//Implementing the remainder of our helper code
void ASpawner::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	WaveNumber = 0;
	TimeUntilNextWave = -1;
	NextWave;

	Super::PostEditChangeProperty(PropertyChangedEvent);

	PlanWave();
	RushWave();

}
#endif
