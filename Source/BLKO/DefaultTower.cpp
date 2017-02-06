// Fill out your copyright notice in the Description page of Project Settings.

#include "BLKO.h"
#include "DefaultTower.h"
#include "DefaultEnemy.h"


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

	AActor::SetLifeSpan(0.1);

	return refund;
}


//Implement Upgrade Function
float ADefaultTower::UpgradeTower()
{
	float price = UpgradeCost;
	Cost += UpgradeCost;
	UpgradeCost = Cost*UpgradeValue;
	Damage *= UpgradeValue;
	AttackSpeed *= UpgradeValue;
	Range *= UpgradeValue;
	UpdateTowerRange(this);
	TowerLevel += 1;
	
	return price;
}

//Implement UpdateTowerRange Function
//This calls the Custom Event in the Blueprint that resizes the Range of the HitBox
void ADefaultTower::UpdateTowerRange(AActor* c)
{	
	FOutputDeviceNull ar;
	c->CallFunctionByNameWithArguments(TEXT("SetTowerRange"), ar, NULL, true);
}

//Implement UpdateCooldown Function
void ADefaultTower::UpdateCooldown()
{
	//AtackSpeed 1 == 1 Shot per second
	//Cooldown = current time  + 1 / tower's AtckSpeed
	FireCooldown = UGameplayStatics::GetRealTimeSeconds(GetWorld()) + (1 / AttackSpeed);
}

//Implement LockOn Function
void ADefaultTower::LockOn(ADefaultEnemy* Target)
{
	if (TargetEnemy == NULL)
		TargetEnemy = Target;
}

//Implement LockOff Function
void ADefaultTower::LockOff(ADefaultEnemy* Target)
{
	if(Target == TargetEnemy)
		TargetEnemy = NULL;
}


//Implement DealDamage Function

void ADefaultTower::DealDamage()
{
	TargetEnemy->DealDamage(Damage);
	UpdateCooldown();
}


//Implement PostEdit
#if WITH_EDITOR
void ADefaultTower::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Cost = 100;
	UpgradeCost = 150;
	UpgradeValue = 1.5;
	Damage = 10;
	AttackSpeed = 1;
	Range = 400;
	FireCooldown = 1;
	TowerLevel = 1;

	Super::PostEditChangeProperty(PropertyChangedEvent);

	SellTower();
	UpgradeTower();
}


#endif