// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceKnightStartLevelController.h"
#include "SpaceKnight.h"



void ASpaceKnightStartLevelController::BeginPlay()
{
	Super::BeginPlay();
	SetInputMode(FInputModeUIOnly());//FInputModeGameAndUI()
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
}




