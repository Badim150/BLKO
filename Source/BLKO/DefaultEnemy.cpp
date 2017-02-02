// Fill out your copyright notice in the Description page of Project Settings.

#include "BLKO.h"
#include "DefaultEnemy.h"


// Sets default values
ADefaultEnemy::ADefaultEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADefaultEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADefaultEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ADefaultEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



//Implement CalculateHealth
void ADefaultEnemy::CalculateHealth(float Delta)
{
	Health += Delta;
	CalculateDead();
}


//Implement CalculateDead
void ADefaultEnemy::CalculateDead()
{
	if (Health <= 0)
		isDead = true;
	else
		isDead = false;
}

//Implement UpgradeEnemy
void ADefaultEnemy::UpgradeEnemy(float RoundNumber)
{
	if (RoundNumber >= 3) {
		RoundNumber = RoundNumber*0.1 + 1;
		Health *= RoundNumber;
		Damage *= RoundNumber;
		MovementSpeed *= RoundNumber;
	}
}

//Implement PostEdit
#if WITH_EDITOR
void ADefaultEnemy::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	isDead = false;
	Health = 100;

	Super::PostEditChangeProperty(PropertyChangedEvent);

	CalculateDead();
}


#endif