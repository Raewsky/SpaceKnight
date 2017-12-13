// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "SpaceKnightSettingsLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SPACEKNIGHT_API USpaceKnightSettingsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "SpaceKnight Video Settings")
	static FString GetCurrentDisplayResolution();

	UFUNCTION(BlueprintPure, Category = "SpaceKnight Video Settings")
	static bool GetSupportedScreenResolutions(TArray<FString>& Resolutions);

	UFUNCTION(BlueprintCallable, Category = "SpaceKnight Video Settings")
	static void setDisplaySettingsComboBoxSelectedOption(UComboBoxString* resolutionComboBox, UComboBoxString* displayModeComboBox, UComboBoxString* graphicsQualityComboBox, UObject* object);

	UFUNCTION(BlueprintCallable, Category = "SpaceKnight Video Settings")
	static void getDisplaySettingsString(FString& resolutionString, FString& displayModeString, FString& graphicsQualityString);

	UFUNCTION(BlueprintCallable, Category = "SpaceKnight Video Settings")
	static bool ChangeVideoSettings(FString resolutionStr, FString displayModeStr, FString graphicsQualityStr, UObject* object);

	UFUNCTION(BlueprintCallable, Category = "SpaceKnight Video Settings")
	static bool ChangeResolutionVideoSettings(FString resolutionStr, FString displayModeStr, UObject* object);

	UFUNCTION(BlueprintCallable, Category = "SpaceKnight Video Settings")
	static bool SetLowVideoQualitySettings(UObject* object);

	UFUNCTION(BlueprintCallable, Category = "SpaceKnight Video Settings")
	static bool SetMediumVideoQualitySettings(UObject* object);

	UFUNCTION(BlueprintCallable, Category = "SpaceKnight Video Settings")
	static bool SetHighVideoQualitySettings(UObject* object);

	UFUNCTION(BlueprintCallable, Category = "SpaceKnight Video Settings")
	static bool SetMaximumVideoQualitySettings(UObject* object);

};
