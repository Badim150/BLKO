// Fill out your copyright notice in the Description page of Project Settings.

#include "BLKO.h"
#include "FinishLine.h"


// Sets default values
AFinishLine::AFinishLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFinishLine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFinishLine::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

