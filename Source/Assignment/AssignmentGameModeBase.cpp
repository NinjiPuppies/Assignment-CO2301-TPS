// Copyright Epic Games, Inc. All Rights Reserved.


#include "AssignmentGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

// Called when the game starts or when spawned
void AAssignmentGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	// Calls start game function.
	StartGame();
}

// Starts the timer.
void AAssignmentGameModeBase::StartGame()
{
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &AAssignmentGameModeBase::TimeUp, GameDuration, false);
}

// Ends the game with the value passed the other functions.
void AAssignmentGameModeBase::GameOver(bool PlayerWon)
{
	if (PlayerWon)
	{
		UE_LOG(LogTemp, Warning, TEXT("You Won"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("You Lost"));
	}
}

// Ends the game if the player runs out of time (Player Loss).
void AAssignmentGameModeBase::TimeUp()
{
	GameOver(false);
	UGameplayStatics::PlaySound2D(GetWorld(), LossSound, 1.0f, 1.0f, 0.0f);
}

// Ends the game if the player destroys the target (Player Win).
void AAssignmentGameModeBase::TargetDestroyed()
{
	GameOver(true);
}

// Ends the game if the player scores all of the bonus points (Player Win).
void AAssignmentGameModeBase::PointScored()
{
	if (CurrentPoints < TargetPoints)
	{
		CurrentPoints++;
		if (CurrentPoints == TargetPoints)
		{
			GameOver(true);
		}
	}
}