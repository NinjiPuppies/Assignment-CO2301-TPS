// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "PlayerCharacter.h"

// Called when the game starts or when spawned
void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Stores a reference to the player in this variable.
	MyPawn = Cast<APlayerCharacter>(GetPawn());

	// Sets the player ammo to 30.
	Ammo = 30;

	// Creates the UI if the widget blueprint is set in the player controller blueprint.
	GameplayUI = CreateWidget(this, GameplayUIClass);
	if (GameplayUI != nullptr)
	{
		GameplayUI->AddToViewport();
	}
	MiniMapUI = CreateWidget(this, MiniMapUIClass);
	if (MiniMapUI != nullptr)
	{
		MiniMapUI->AddToViewport();
	}
}

// Called to bind functionality to input from the player.
void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);
	InputComponent->BindAxis("Forwards", this, &AMyPlayerController::CallForwards);
	InputComponent->BindAxis("Turn", this, &AMyPlayerController::CallTurn);
	InputComponent->BindAxis("Strafe", this, &AMyPlayerController::CallStrafe);
	InputComponent->BindAxis("LookUp", this, &AMyPlayerController::CallLookUp);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &AMyPlayerController::CallFire);
}

// This function tells the player to call its function 'Forwards'.
void AMyPlayerController::CallForwards(float Value)
{
	if (MyPawn)
	{
		MyPawn->Forwards(Value);
	}
}

// This function tells the player to call its function 'Turn'.
void AMyPlayerController::CallTurn(float Value)
{
	if (MyPawn)
	{
		MyPawn->Turn(Value);
	}
}

// This function tells the player to call its function 'Strafe'.
void AMyPlayerController::CallStrafe(float Value)
{
	if (MyPawn)
	{
		MyPawn->Strafe(Value);
	}
}

// This function tells the player to call its function 'LookUp'.
void AMyPlayerController::CallLookUp(float Value)
{
	if (MyPawn)
	{
		MyPawn->LookUp(Value);
	}
}

// This function tells the player to call its function 'EndFire'.
void AMyPlayerController::CallFire()
{
	if (MyPawn)
	{
		// Only fires if the player has ammo remaining.
		if (Ammo > 0)
		{
			Ammo--;
			MyPawn->EndFire();
		}
		else if (Ammo == 0)
		{
			return;
		}
	}
}

// This function checks how much ammo the player has left, it is then used to update the widget blueprint.
int AMyPlayerController::GetAmmo()
{
	return Ammo;
}