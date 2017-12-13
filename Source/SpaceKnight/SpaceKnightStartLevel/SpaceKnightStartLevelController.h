// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "SpaceKnightStartLevelController.generated.h"

/**
 * 
 */
UCLASS()
class SPACEKNIGHT_API ASpaceKnightStartLevelController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
};


