// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SpaceKnightLibrary/SpaceKnightSettingsLibrary.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceKnightStartLevelGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SPACEKNIGHT_API ASpaceKnightStartLevelGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	/*Change Widget to NewWidget*/
	UFUNCTION(BlueprintCallable, Category = "SpaceKnight UMG Game")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	UFUNCTION(BlueprintCallable, Category = "SpaceKnight Video Settings")
	void RemoveCurrentWidget();

	UFUNCTION(BlueprintCallable, Category = "SpaceKnight Video Settings")
	void InitGraphicsSettings();

protected:
	/** Called when the game starts. */
	virtual void BeginPlay() override;

	/** The widget class we will use as our menu when the game starts. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SpaceKnight UMG Game")
	TSubclassOf<UUserWidget> StartingWidgetClass;

	/** The widget instance that we are using as our menu. */
	UPROPERTY()
	UUserWidget* CurrentWidget;
};
