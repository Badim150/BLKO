// Fill out your copyright notice in the Description page of Project Settings.

#include "BLKO.h"
#include "DefaultTower.h"


// Sets default values
ADefaultTower::ADefaultTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


// Called when the game starts or when spawned
void ADefaultTower::BeginPlay()
{
	Super::BeginPlay();	
}


// Called every frame
void ADefaultTower::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


//Implement Sell Function
float ADefaultTower::SellTower()
{
	float refund = Cost*0.5;

//	AActor::SetLifeSpan(2);

	return refund;
}


//Implement Upgrade Function
void ADefaultTower::UpgradeTower()
{
	Cost += UpgradeCost;
	UpgradeCost = Cost*UpgradeValue;
	Damage *= UpgradeValue;
	AttackSpeed *= UpgradeValue;
	Range *= UpgradeValue;
}


//Impelment UpdateCooldown Function
void ADefaultTower::UpdateCooldown()
{
	//AtackSpeed 1 == 1 Shot per second
	//Cooldown = current time  + 1 / tower's AtckSpeed
	FireCooldown = UGameplayStatics::GetRealTimeSeconds(GetWorld()) + (1 / AttackSpeed);
}


//Implement DealDamage Function
void ADefaultTower::DealDamage(AActor *target)
{
	UGameplayStatics::ApplyDamage(target, Damage, NULL,NULL,NULL);
	UpdateCooldown();
}


//Implement PostEdit
#if WITH_EDITOR
void ADefaultTower::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Cost = 10;
	UpgradeCost = 15;
	UpgradeValue = 1.5;
	Damage = 10;
	AttackSpeed = 10;
	Range = 5;
	FireCooldown = 1;

	Super::PostEditChangeProperty(PropertyChangedEvent);

	SellTower();
	UpgradeTower();
}


#endif