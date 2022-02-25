// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

// Forward declares the projectile movement class.
class UProjectileMovementComponent;

UCLASS()
class ASSIGNMENT_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// The mesh component for the bullet.
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BulletMesh;

	// The projectile movement component for the bullet.
	UPROPERTY(VisibleAnywhere)
		UProjectileMovementComponent* ProjectileMovement;

	// The damage the bullet deals.
	UPROPERTY(EditAnywhere)
		float Damage = 10.0f;

	// The movement speed of the bullet.
	UPROPERTY(EditAnywhere)
		float MovementSpeed = 2500.0f;

	// This function acts as a dynamic delegate of the OnActorHit function.
	UFUNCTION()
		void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

};
