// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceKnightStartLevelGameModeBase.h"
#include "SpaceKnight.h"
#include "SpaceKnightLibrary/SpaceKnightSettingsLibrary.h"
#include "SpaceKnightSave/SpaceKnightSettingsSave.h"
#include "SpaceKnightStartLevelController.h"
#include "SpaceKnightStartLevelCharacter.h"


void ASpaceKnightStartLevelGameModeBase::BeginPlay()
{
	Super::BeginPlay(); 

	//if(GetWorld()->GetName().Equals("SpaceKnightStartLevel")){
	//}
	ChangeMenuWidget(StartingWidgetClass);
	ASpaceKnightStartLevelGameModeBase::InitGraphicsSettings();
}

void ASpaceKnightStartLevelGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void ASpaceKnightStartLevelGameModeBase::RemoveCurrentWidget() {
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
}

void ASpaceKnightStartLevelGameModeBase::InitGraphicsSettings() {
	FString resolutionString = "";
	FString displayModeString = "";
	FString graphicsQualityString = "";

	USpaceKnightSettingsLibrary::getDisplaySettingsString(resolutionString, displayModeString, graphicsQualityString);
	USpaceKnightSettingsLibrary::ChangeVideoSettings(resolutionString, displayModeString, graphicsQualityString, this);
	USpaceKnightSettingsSave::USpaceKnightSettingsSave::saveResolutionStringToSaveSlot(resolutionString, displayModeString, graphicsQualityString);
}





