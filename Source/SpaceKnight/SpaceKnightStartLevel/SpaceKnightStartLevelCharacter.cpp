// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceKnightStartLevelCharacter.h"
#include "SpaceKnight.h"



// Sets default values
ASpaceKnightStartLevelCharacter::ASpaceKnightStartLevelCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpaceKnightStartLevelCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceKnightStartLevelCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceKnightStartLevelCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

