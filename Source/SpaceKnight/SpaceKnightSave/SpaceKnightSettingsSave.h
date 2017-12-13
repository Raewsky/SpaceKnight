// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "SpaceKnightSettingsSave.generated.h"


/**
 * 
 */
UCLASS()
class SPACEKNIGHT_API USpaceKnightSettingsSave : public USaveGame
{
	GENERATED_BODY()
public:
	USpaceKnightSettingsSave();

	UFUNCTION(BlueprintCallable, Category = "SpaceKnight Settings Save")
	static void getDisplaySettingsStringFromSaveSlot(FString& resolutionStr, FString& displayModeStr, FString& graphicsQualityStr);

	UFUNCTION(BlueprintCallable, Category = "SpaceKnight Settings Save")
	static void saveResolutionStringToSaveSlot(FString resolutionStr, FString displayModeStr, FString graphicsQualityStr);

private:
	UPROPERTY(VisibleAnywhere, Category = "SpaceKnight Settings Save")
	FString resolutionString;

	UPROPERTY(VisibleAnywhere, Category = "SpaceKnight Settings Save")
	FString displayModeString;

	UPROPERTY(VisibleAnywhere, Category = "SpaceKnight Settings Save")
	FString graphicsQualityString;


	UPROPERTY(VisibleAnywhere, Category = "SpaceKnight Settings Save")
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = "SpaceKnight Settings Save")
	uint32 UserIndex;



	
};
