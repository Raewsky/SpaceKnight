// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceKnightSettingsSave.h"
#include "SpaceKnight.h"
#include "Kismet/GameplayStatics.h"

USpaceKnightSettingsSave::USpaceKnightSettingsSave()
{
	SaveSlotName = TEXT("SpaceKnightSettingsSaveSlot");
	UserIndex = 0;
}

void USpaceKnightSettingsSave::getDisplaySettingsStringFromSaveSlot(FString& resolutionStr, FString& displayModeStr, FString& graphicsQualityStr)
{
	USpaceKnightSettingsSave* LoadGameInstance = Cast<USpaceKnightSettingsSave>(UGameplayStatics::CreateSaveGameObject(USpaceKnightSettingsSave::StaticClass()));
	LoadGameInstance = Cast<USpaceKnightSettingsSave>(UGameplayStatics::LoadGameFromSlot(LoadGameInstance->SaveSlotName, LoadGameInstance->UserIndex));
	if (IsValid(LoadGameInstance)) {
		resolutionStr = LoadGameInstance->resolutionString;
		displayModeStr = LoadGameInstance->displayModeString;
		graphicsQualityStr = LoadGameInstance->graphicsQualityString;
	}

}

void USpaceKnightSettingsSave::saveResolutionStringToSaveSlot(FString resolutionStr, FString displayModeStr, FString graphicsQualityStr) {
	USpaceKnightSettingsSave* SaveGameInstance = Cast<USpaceKnightSettingsSave>(UGameplayStatics::CreateSaveGameObject(USpaceKnightSettingsSave::StaticClass()));
	SaveGameInstance->resolutionString = resolutionStr;
	SaveGameInstance->displayModeString = displayModeStr;
	SaveGameInstance->graphicsQualityString = graphicsQualityStr;
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveGameInstance->SaveSlotName, SaveGameInstance->UserIndex);
}







