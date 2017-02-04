// Fill out your copyright notice in the Description page of Project Settings.


#include "BLKO.h"
#include "DefaultProjectile.h"
#include "DefaultEnemy.h"



// Sets default values
ADefaultProjectile::ADefaultProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADefaultProjectile::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(1);
	
}

// Called every frame
void ADefaultProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	UpdateTarget();
}


//Implement DealDamage
void ADefaultProjectile::DealDamage()
{
	Target->DealDamage(Damage);
	Destroy();
	
	
}

//Implement InitProjectile
void ADefaultProjectile::InitProjectile(float dmg, ADefaultEnemy *tar)
{
	Damage = dmg;
	Target = tar;

}

//Implement UpdateTarget
void ADefaultProjectile::UpdateTarget()
{
	if (Target->isDead)
		Destroy();

}

//Implement PostEdit
#if WITH_EDITOR
void ADefaultProjectile::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Damage = 1;

	Super::PostEditChangeProperty(PropertyChangedEvent);

}


#endif
