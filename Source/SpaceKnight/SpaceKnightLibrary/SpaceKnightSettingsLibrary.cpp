// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceKnightLibrary/SpaceKnightSettingsLibrary.h"
#include "SpaceKnight.h"
#include "SpaceKnightSave/SpaceKnightSettingsSave.h"
#include "CustomUIComponent/ResolutionComboBoxString.h"

FString USpaceKnightSettingsLibrary::GetCurrentDisplayResolution() {
	FString res;
	FDisplayMetrics Display;
	//FDisplayMetrics::GetDisplayMetrics(Display);

	FString StrW = FString::FromInt(Display.PrimaryDisplayWidth);
	FString StrH = FString::FromInt(Display.PrimaryDisplayHeight);
	res = StrW.Append("x").Append(StrH);
	return res;
}

bool USpaceKnightSettingsLibrary::GetSupportedScreenResolutions(TArray<FString>& Resolutions)
{
	FScreenResolutionArray ResolutionsArray;

	if (RHIGetAvailableResolutions(ResolutionsArray, true))  // "RHI" dependency
	{
		for (const FScreenResolutionRHI& Resolution : ResolutionsArray)
		{
			FString StrW = FString::FromInt(Resolution.Width);
			FString StrH = FString::FromInt(Resolution.Height);
			FString StrRes = StrW.Append("x").Append(StrH);
			//UE_LOG(LogWindows, Log, TEXT("USpaceKnightSettingsLibrary::GetSupportedScreenResolutions: %s"), *StrRes);
			Resolutions.AddUnique(StrRes);
		}
		return true;
	}
	return false;  // failed to obtain screen resolutions
}



void USpaceKnightSettingsLibrary::setDisplaySettingsComboBoxSelectedOption(UComboBoxString* resolutionComboBox, UComboBoxString* displayModeComboBox, UComboBoxString* graphicsQualityComboBox, UObject* object)
{
	FString resolutionString = "";
	FString displayModeString = "";
	FString graphicsQualityString = "";

	USpaceKnightSettingsLibrary::getDisplaySettingsString(resolutionString, displayModeString, graphicsQualityString);

	//resolutionComboBox
	resolutionComboBox->UComboBoxString::SetSelectedOption(resolutionString);
	//displayModeComboBox
	displayModeComboBox->UComboBoxString::SetSelectedOption(displayModeString);
	//graphicsQualityString
	graphicsQualityComboBox->UComboBoxString::SetSelectedOption(graphicsQualityString);
}


void USpaceKnightSettingsLibrary::getDisplaySettingsString(FString& resolutionString, FString& displayModeString, FString& graphicsQualityString) {
	
	USpaceKnightSettingsSave::getDisplaySettingsStringFromSaveSlot(resolutionString, displayModeString, graphicsQualityString);

	//resolution
	if (resolutionString.IsEmpty()) {
		FString StrRes = USpaceKnightSettingsLibrary::GetCurrentDisplayResolution();
		resolutionString = StrRes;
	}

	//displayMode
	if (displayModeString.IsEmpty())
		displayModeString = "Full Screen";//Windowed

	//graphicsQualityString
	if (graphicsQualityString.IsEmpty())
		graphicsQualityString = "Maximum";
}



bool USpaceKnightSettingsLibrary::ChangeVideoSettings(FString resolutionStr, FString displayModeStr, FString graphicsQualityStr, UObject* object) {
	UE_LOG(LogWindows, Log, TEXT("USpaceKnightSettingsLibrary::ChangeVideoSettings: resolutionStr = %s  displayModeStr = %s  graphicsQualityStr = %s "), *resolutionStr , *displayModeStr, *graphicsQualityStr);
	USpaceKnightSettingsLibrary::ChangeResolutionVideoSettings(resolutionStr, displayModeStr, object);
	USpaceKnightSettingsSave::saveResolutionStringToSaveSlot(resolutionStr, displayModeStr, graphicsQualityStr);

	if (graphicsQualityStr.Equals("Low")) {
		USpaceKnightSettingsLibrary::SetLowVideoQualitySettings(object);
	}
	if (graphicsQualityStr.Equals("Medium")) {
		USpaceKnightSettingsLibrary::SetMediumVideoQualitySettings(object);
	}
	if (graphicsQualityStr.Equals("High")) {
		USpaceKnightSettingsLibrary::SetHighVideoQualitySettings(object);
	}
	if (graphicsQualityStr.Equals("Maximum")) {
		USpaceKnightSettingsLibrary::SetMaximumVideoQualitySettings(object);
	}

	return true;
}

bool USpaceKnightSettingsLibrary::ChangeResolutionVideoSettings(FString resolutionStr, FString displayModeStr, UObject* object) {
	FString executeCommandString = "r.setRes ";
	if (!resolutionStr.IsEmpty() && !displayModeStr.IsEmpty()) {
		if (displayModeStr.Equals("Windowed"))
			displayModeStr = "w";
		else
			displayModeStr = "f";

		executeCommandString.Append(resolutionStr).Append(displayModeStr);
	}
	UE_LOG(LogWindows, Log, TEXT("USpaceKnightSettingsLibrary::ChangeResolutionVideoSettings: executeCommandString = %s  "), *executeCommandString);
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString, ((APlayerController*)nullptr));

	return true;
}



bool USpaceKnightSettingsLibrary::SetLowVideoQualitySettings(UObject* object) {
	int32 AntiAliasingQuality = 0;
	int32 EffectsQuality = 0;
	int32 PostProcessQuality = 0;
	int32 ResolutionQuality = 60;
	int32 ShadowQuality = 0;
	int32 TextureQuality = 0;
	int32 ViewDistanceQuality = 1;
	int32 FoliageQuality = 0;

	FString executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("r.PostProcessAAQuality ").Append(FString::FromInt(AntiAliasingQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.EffectsQuality ").Append(FString::FromInt(EffectsQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.PostProcessQuality ").Append(FString::FromInt(PostProcessQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("r.ScreenPercentage ").Append(FString::FromInt(ResolutionQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.ShadowQuality ").Append(FString::FromInt(ShadowQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.TextureQuality ").Append(FString::FromInt(TextureQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("r.ViewDistanceScale ").Append(FString::FromInt(ViewDistanceQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.FoliageQuality ").Append(FString::FromInt(FoliageQuality)), ((APlayerController*)nullptr));
	
	return true;
}

bool USpaceKnightSettingsLibrary::SetMediumVideoQualitySettings(UObject* object) {
	int32 AntiAliasingQuality = 2;
	int32 EffectsQuality = 1;
	int32 PostProcessQuality = 1;
	int32 ResolutionQuality = 90;
	int32 ShadowQuality = 1;
	int32 TextureQuality = 1;
	int32 ViewDistanceQuality = 1;
	int32 FoliageQuality = 1;

	FString executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("r.PostProcessAAQuality ").Append(FString::FromInt(AntiAliasingQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.EffectsQuality ").Append(FString::FromInt(EffectsQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.PostProcessQuality ").Append(FString::FromInt(PostProcessQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("r.ScreenPercentage ").Append(FString::FromInt(ResolutionQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.ShadowQuality ").Append(FString::FromInt(ShadowQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.TextureQuality ").Append(FString::FromInt(TextureQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("r.ViewDistanceScale ").Append(FString::FromInt(ViewDistanceQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.FoliageQuality ").Append(FString::FromInt(FoliageQuality)), ((APlayerController*)nullptr));

	return true;
}

bool USpaceKnightSettingsLibrary::SetHighVideoQualitySettings(UObject* object) {
	int32 AntiAliasingQuality = 4;
	int32 EffectsQuality = 2;
	int32 PostProcessQuality = 2;
	int32 ResolutionQuality = 90;
	int32 ShadowQuality = 2;
	int32 TextureQuality = 2;
	int32 ViewDistanceQuality = 1;
	int32 FoliageQuality = 2;

	FString executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("r.PostProcessAAQuality ").Append(FString::FromInt(AntiAliasingQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.EffectsQuality ").Append(FString::FromInt(EffectsQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.PostProcessQuality ").Append(FString::FromInt(PostProcessQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("r.ScreenPercentage ").Append(FString::FromInt(ResolutionQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.ShadowQuality ").Append(FString::FromInt(ShadowQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.TextureQuality ").Append(FString::FromInt(TextureQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("r.ViewDistanceScale ").Append(FString::FromInt(ViewDistanceQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.FoliageQuality ").Append(FString::FromInt(FoliageQuality)), ((APlayerController*)nullptr));

	return true;
}


bool USpaceKnightSettingsLibrary::SetMaximumVideoQualitySettings(UObject* object) {
	int32 AntiAliasingQuality = 6;
	int32 EffectsQuality = 3;
	int32 PostProcessQuality = 3;
	int32 ResolutionQuality = 100;
	int32 ShadowQuality = 3;
	int32 TextureQuality = 3;
	int32 ViewDistanceQuality = 1;
	int32 FoliageQuality = 3;

	FString executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("r.PostProcessAAQuality ").Append(FString::FromInt(AntiAliasingQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.EffectsQuality ").Append(FString::FromInt(EffectsQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.PostProcessQuality ").Append(FString::FromInt(PostProcessQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("r.ScreenPercentage ").Append(FString::FromInt(ResolutionQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.ShadowQuality ").Append(FString::FromInt(ShadowQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.TextureQuality ").Append(FString::FromInt(TextureQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("r.ViewDistanceScale ").Append(FString::FromInt(ViewDistanceQuality)), ((APlayerController*)nullptr));
	executeCommandString = "";
	UKismetSystemLibrary::ExecuteConsoleCommand(object, executeCommandString.Append("sg.FoliageQuality ").Append(FString::FromInt(FoliageQuality)), ((APlayerController*)nullptr));

	return true;
}
