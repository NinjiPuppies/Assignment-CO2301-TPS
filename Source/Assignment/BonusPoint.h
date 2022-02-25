// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BonusPoint.generated.h"

// Forward declares the collision component class and game mode base.
class UBoxComponent;
class AAssignmentGameModeBase;

UCLASS()
class ASSIGNMENT_API ABonusPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABonusPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
	// The mesh component for the bonus point.
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PointMesh;

	// The collision component for the bonus point.
	UPROPERTY(EditAnywhere)
		UBoxComponent* CollisionBox;

	// Sound played when a point is picked up.
	UPROPERTY(EditAnywhere)
		USoundBase* Scored;

	// Creates a reference for the class to use functions within game mode base.
	UPROPERTY()
		AAssignmentGameModeBase* GameModeRef;

	// This function acts as a dynamic delegate of the OnOverlapBegin function.
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// This function acts as a dynamic delegate of the OnOverlapEnd function.
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
