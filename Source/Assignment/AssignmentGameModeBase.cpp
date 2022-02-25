// Copyright Epic Games, Inc. All Rights Reserved.


#include "AssignmentGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AAssignmentGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	StartGame();
}

void AAssignmentGameModeBase::StartGame()
{
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &AAssignmentGameModeBase::TimeUp, GameDuration, false);
}


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

void AAssignmentGameModeBase::TimeUp()
{
	GameOver(false);
}

void AAssignmentGameModeBase::TargetDestroyed()
{
	GameOver(true);
}

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