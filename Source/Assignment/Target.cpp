// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"
#include "Kismet/GameplayStatics.h"
#include "AssignmentGameModeBase.h"

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates a mesh for the target and assigns it to the root component.
	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetMesh"));
	SetRootComponent(TargetMesh);

	// The target mesh will fire hit events when it collides with something.
	TargetMesh->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorHit.AddDynamic(this, &ATarget::HandleHit);
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Handles taking damage from another actor
float ATarget::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Health -= DamageAmount;
	if (Health <= 0.0f)
	{
		// Destroys target if it has no health left.
		Destroy();
		GameModeRef->TargetDestroyed();
	}
	// Returns the damage taken by the target on this hit.
	return DamageAmount;
}

// This function destroys the bullet when it collides with the target
void ATarget::HandleHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	OtherActor->Destroy();
}
