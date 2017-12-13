// Fill out your copyright notice in the Description page of Project Settings.

#include "ResolutionComboBoxString.h"
#include "SpaceKnight.h"
#include "SpaceKnightSave/SpaceKnightSettingsSave.h"


// Sets default values
UResolutionComboBoxString::UResolutionComboBoxString()
{
	Super::ClearOptions();
	TArray<FString> Resolutions;
	USpaceKnightSettingsLibrary::GetSupportedScreenResolutions(Resolutions);

	for (FString str : Resolutions) {
		Super::AddOption(str);
	}
}




