// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */

// Forward declares the player class and widget class.
class UUserWidget;
class APlayerCharacter;

UCLASS()
class ASSIGNMENT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;
	// Declares the functions required to call player movement and weapon firing.
	virtual void CallForwards(float Value);
	virtual void CallTurn(float Value);
	virtual void CallStrafe(float Value);
	virtual void CallLookUp(float Value);
	virtual void CallFire();

	// A pointer to the player class.
	APlayerCharacter* MyPawn;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// This is a subclass of the widget class for use in creating ui elements.
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> GameplayUIClass;

	// Used to create the widget and add it to the viewport.
	UPROPERTY()
		UUserWidget* GameplayUI;

	// Sets the ammo of the player.
	UPROPERTY(VisibleAnywhere)
		int Ammo = 30;

	// This function checks how much ammo the player has left. It is only used in the widget blueprint.
	UFUNCTION(BlueprintPure)
		int GetAmmo();
};