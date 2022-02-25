// Fill out your copyright notice in the Description page of Project Settings.


#include "BonusPoint.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AssignmentGameModeBase.h"

// Sets default values
ABonusPoint::ABonusPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates a mesh for the bonus point and assigns it to the root component.
	PointMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PointMesh"));
	SetRootComponent(PointMesh);

	// Creates a collision for the bonus point and assigns it to the root component.
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	CollisionBox->SetBoxExtent(FVector(64.0f, 64.0f, 64.0f));
	CollisionBox->SetCollisionProfileName("Trigger");
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	CollisionBox->SetupAttachment(PointMesh);
}

// Called when the game starts or when spawned
void ABonusPoint::BeginPlay()
{
	Super::BeginPlay();
	
	// Gets a reference to the world in order to allow the points to disappear.
	GameModeRef = Cast<AAssignmentGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	// Creates the dynamic delegate links to the OnComponentOverlap functions.
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABonusPoint::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ABonusPoint::OnOverlapEnd);
}

// Called every frame
void ABonusPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// This function acts as a dynamic delegate of the OnOverlapBegin function.
void ABonusPoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// The plauer adds to their score and then the point is destroyed.
	GameModeRef->PointScored();
	Destroy();
}

// This function acts as a dynamic delegate of the OnOverlapEnd function.
void ABonusPoint::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), Scored, GetActorLocation(), 1.0f, 1.0f, 0.0f);
}
