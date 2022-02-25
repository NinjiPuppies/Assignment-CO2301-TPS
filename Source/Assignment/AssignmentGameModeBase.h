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

	UFUNCTION()
		void PointScored();

	UFUNCTION()
		void TargetDestroyed();

protected:
	virtual void BeginPlay() override;

private:

	FTimerHandle Timer;

	UPROPERTY(EditAnywhere)
		float GameDuration = 45.0f;

	UPROPERTY(VisibleAnywhere)
		int TargetPoints = 5;

	UPROPERTY(VisibleAnywhere)
		int CurrentPoints = 0;

	UFUNCTION()
		void StartGame();

	UFUNCTION()
		void GameOver(bool PlayerWon);

	UFUNCTION()
		void TimeUp();
	
};
