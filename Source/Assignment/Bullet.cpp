// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "Target.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates a mesh for the bullet and assigns it to the root component.
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	SetRootComponent(BulletMesh);

	// The bullet mesh will simulate physics and fire hit events when it collides with something.
	BulletMesh->SetSimulatePhysics(true);
	BulletMesh->SetNotifyRigidBodyCollision(true);

	// Creates the projectile movement component then sets it initial and max speed to the movement speed variable in the header file.
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->MaxSpeed = MovementSpeed;
	ProjectileMovement->InitialSpeed = MovementSpeed;

	// Sets the bullets to stay on screen for 5 seconds before deleting.
	InitialLifeSpan = 5.0f;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	OnActorHit.AddDynamic(this, &ABullet::OnHit);
}

void ABullet::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	// Checks for the actor who spawned the projectile.
	AActor* ProjectileOwner = GetOwner();

	// If there is none it will return early.
	if (!ProjectileOwner)
	{
		UE_LOG(LogTemp, Error, TEXT("Bullet owner not set"));
		return;
	}

	// If the object hit is a target it will apply damage to it.
	if (OtherActor->GetClass()->IsChildOf(ATarget::StaticClass())) 
	{
		// Applies damage to the other actor.
		UGameplayStatics::ApplyDamage(OtherActor, Damage, ProjectileOwner->GetInstigatorController(), this, UDamageType::StaticClass());
		// Destroys bullet so it cannot continue to collide.
		Destroy();
	}
}
