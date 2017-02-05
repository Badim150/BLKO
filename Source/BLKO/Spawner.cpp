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
	GetWaveFromFile();

}

// Called every frame
void ASpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (Enabled) {
		float _gameTime = UGameplayStatics::GetRealTimeSeconds(GetWorld());
		if (NextWave.IsEmpty()) {
			PlanWave(this, TimeWave);
		}
		else if (_gameTime >= TimeToSpawn) {
			SpawnEnemy(this);
		}
	}		
}


//Implement the PlanWave function.
void ASpawner::PlanWave(AActor* c, float t)
{
	FString temp;
	WaveString.Split("\n", &temp, &WaveString, ESearchCase::CaseSensitive, ESearchDir::FromStart);
	NextWave.Append(temp);

	WaveNumber += 1;
	UpdateSpawnTime(t);
	FOutputDeviceNull ar;
	c->CallFunctionByNameWithArguments(TEXT("InformGameControlNewWave"), ar, NULL, true);

}


//Implement the SpawnEnemy function.
void ASpawner::SpawnEnemy(AActor* c)
{
	//Remove 1st enemy in the list and spawn it	
	FOutputDeviceNull ar;
	std::string nextEnemy(1, NextWave[0]);
	FString temp(nextEnemy.c_str());
	EnemyToSpawn = temp;
	NextWave.RemoveFromStart(EnemyToSpawn);
	c->CallFunctionByNameWithArguments(TEXT("BPSpawnEnemy"), ar, NULL, true);
	UpdateSpawnTime(TimeMob);
}

//Implement UpdateSpawnTime
void ASpawner::UpdateSpawnTime(float tm)
{
	TimeToSpawn = UGameplayStatics::GetRealTimeSeconds(GetWorld()) + tm;

}

//Implement the RushWave function.
void ASpawner::RushWave()
{
	PlanWave(this, TimeMob);
}

//Implement the GetWaveFromFile function.
void ASpawner::GetWaveFromFile() 
{
	FFileHelper::LoadFileToString(WaveString, *(FPaths::GameDir() + "Waves.txt"));
		
}

//Implement EnableSpawner function
void ASpawner::EnableSpawner(int wave) {
	Enabled = true;
}

//Implement DisableSpawner function
void ASpawner::DisableSpawner() {
	SetLifeSpan(20);
}

//Implement EnableSpawner function
void ASpawner::HardMode(int wave) {
	NextWave.Empty();
	WaveNumber = wave;
	PlanWave(this, 20);

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




#if WITH_EDITOR
//Implementing the remainder of our helper code
void ASpawner::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	WaveNumber = 0;
	TimeUntilNextWave = -1;
	NextWave;

	Super::PostEditChangeProperty(PropertyChangedEvent);

}
#endif
