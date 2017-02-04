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
	WaveNumber = 0;
	
}

// Called every frame
void ASpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	float _gameTime = UGameplayStatics::GetRealTimeSeconds(GetWorld());
	
	if (NextWave.length() <= 0) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "gonna plan msg");
		PlanWave();
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "gona wave msg");
		UpdateSpawnTime(2);// HERE
		
	}else if (_gameTime >= TimeToSpawn) {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "gonna spawn msg");
		SpawnEnemy(this);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "I spawned msg");
		UpdateSpawnTime(1);
	}

	
}


//Implement the PlanWave function.
void ASpawner::PlanWave()
{
	NextWave = WaveString[WaveNumber];
	
	WaveNumber += 1;

}



//Implement the SpawnEnemy function.
void ASpawner::SpawnEnemy(AActor* c)
{
	FOutputDeviceNull ar;
	std::string nextEnemy(1, NextWave.c_str()[0]);
	FString temp(nextEnemy.c_str());
	EnemyToSpawn = temp;

	//	NextWave.erase(0);
	c->CallFunctionByNameWithArguments(TEXT("BPSpawnEnemy"), ar, NULL, true);
	
}

//Implement UpdateSpawnTime
void ASpawner::UpdateSpawnTime(float tm)
{
	TimeToSpawn = UGameplayStatics::GetRealTimeSeconds(GetWorld()) + tm;

}

//Implement the RushWave function.
void ASpawner::RushWave()
{
//TODO
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

	PlanWave();
	RushWave();

}
#endif
