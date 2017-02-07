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
void ADefaultEnemy::DealDamage(float Delta)
{
	Health -= Delta;
	CalculateDead(this);
}


//Implement CalculateDead
void ADefaultEnemy::CalculateDead(AActor* c)
{
	FOutputDeviceNull ar;
	
	if (Health <= 0)
	{
		isDead = true;
		c->CallFunctionByNameWithArguments(TEXT("DeathState"), ar, NULL, true);
	}
	
}

//Implement UpgradeEnemy
void ADefaultEnemy::UpgradeEnemy(int RoundNumber)
{	
		//An enemy is upgraded according to the current Wave
	
		float _roundNumber = RoundNumber*2 ;
		Health +=  _roundNumber*2.5;
		MaxHealth += _roundNumber*2.5;
		Damage += _roundNumber/2;
		MovementSpeed += _roundNumber;
		Worth += _roundNumber*1.5;
		
}



//Implement PostEdit
#if WITH_EDITOR
void ADefaultEnemy::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Health = 10;
	MaxHealth = 10;
	Worth = 15;
	Damage = 1;
	MovementSpeed = 100;
	isDead = false;

	Super::PostEditChangeProperty(PropertyChangedEvent);

}


#endif