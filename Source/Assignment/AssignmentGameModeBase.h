// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AssignmentGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API AAssignmentGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	
	// Stores the players current points.
	UPROPERTY(VisibleAnywhere)
		int CurrentPoints = 0;

	//This function adds a point when the player picks up the bonus points item.
	UFUNCTION()
		void PointScored();

	//This function ends the game when the target is destroyed.
	UFUNCTION()
		void TargetDestroyed();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// This struct is used to time the game.
	FTimerHandle Timer;

	// This is the set duration for the timer.
	UPROPERTY(EditAnywhere)
		float GameDuration = 45.0f;

	// This is the target points for the player to win.
	UPROPERTY(VisibleAnywhere)
		int TargetPoints = 5;

	// Starts the timer.
	UFUNCTION()
		void StartGame();

	// Ends the game with the value passed the other functions.
	UFUNCTION()
		void GameOver(bool PlayerWon);

	// Ends the game if the player runs out of time (Player Loss).
	UFUNCTION()
		void TimeUp();
};
