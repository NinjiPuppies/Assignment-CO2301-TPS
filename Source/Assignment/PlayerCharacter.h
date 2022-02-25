// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

// Forward declares the bullet class and game mode base.
class ABullet;
class AAssigmentGameModeBase;

UCLASS()
class ASSIGNMENT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	// This is a subclass of the bullet class for use in spawning projectiles.
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABullet> BulletClass;

	// This is a spawn point for the projectiles.
	UPROPERTY(EditAnywhere)
		USceneComponent* ProjectileSpawn;

	// Sets the health of the player.
	UPROPERTY(VisibleAnywhere)
		float Health = 100.0f;

	//UPROPERTY()
	//	AAssignmentGameModeBase* GameModeRef;

	// Declares the functions required for player movement and weapon firing.
	UFUNCTION()
		void Forwards(float Value);

	UFUNCTION()
		void Strafe(float Value);

	UFUNCTION()
		void Turn(float Value);
	
	UFUNCTION()
		void LookUp(float Value);

	UFUNCTION()
		void StartFire();

	UFUNCTION()
		void EndFire();
};
