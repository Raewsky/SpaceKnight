// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SpaceKnightSave/SpaceKnightSettingsSave.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Components/ComboBoxString.h"
#include "SpaceKnightLibrary/SpaceKnightSettingsLibrary.h"
#include "ResolutionComboBoxString.generated.h"

/**
 * 
 */
UCLASS()
class SPACEKNIGHT_API UResolutionComboBoxString : public UComboBoxString
{
	GENERATED_BODY()

public:
	// Sets default values for this ComboBox
	UResolutionComboBoxString();

	//UFUNCTION(BlueprintCallable, Category = "SpaceKnight Video Settings")
	//void setDisplayResolutionSelectedOption();
};
