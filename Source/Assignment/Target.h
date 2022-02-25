// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

// Forward declares the game mode base.
class AAssignmentGameModeBase;

UCLASS()
class ASSIGNMENT_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// Overrides the base take damage function with a custom definition.
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	// The mesh component for the target.
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* TargetMesh;

	// Sets the health of the target.
	UPROPERTY(EditAnywhere)
		float Health = 100.0f;

	// Sound played when target destroyed.
	UPROPERTY(EditAnywhere)
		USoundBase* TargetSound;

	// Creates a reference for the class to use functions within game mode base.
	UPROPERTY()
		AAssignmentGameModeBase* GameModeRef;

	// This function handles how the target reacts to a hit (by destroying the bullet).
	UFUNCTION()
		void HandleHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
