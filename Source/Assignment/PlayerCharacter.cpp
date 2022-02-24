// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Bullet.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it
	PrimaryActorTick.bCanEverTick = true;

	// Ensures the player starts possessing this character.
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Creates a projectile spawn point and attaches it to the players skeletal mesh at the below location.
	ProjectileSpawn = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawn"));
	ProjectileSpawn->SetupAttachment(GetMesh());
	ProjectileSpawn->SetRelativeLocation(FVector(-16.0f, 56.0f, 113.0f));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input from the player.
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forwards", this, &APlayerCharacter::Forwards);
	PlayerInputComponent->BindAxis("Strafe", this, &APlayerCharacter::Strafe);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::Jump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &APlayerCharacter::EndFire);
}

// This function allows the player to move forwards/backwards using the AddMovementInput function and the input value from the player and their forward vector.
void APlayerCharacter::Forwards(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

// This function allows the player to move left/right using the AddMovementInput function and the input value from the player and their right vector.
void APlayerCharacter::Strafe(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}

// This function allows the player to look left/right using the AddControllerYawInput function and the input value from the player.
void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

// This function allows the player to look up/down using the AddControllerPitchInput function and the input value from the player.
void APlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

// This function controls what happens when the player begins firing their weapon.
void APlayerCharacter::StartFire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Pressed"));
}

// This function controls what happens when the player begins firing their weapon.
void APlayerCharacter::EndFire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Released"));
	if (BulletClass) { // Ensures that the Bullet projectile is set in the blueprint of the player.
		FVector SpawnLocation = ProjectileSpawn->GetComponentLocation(); // Sets the spawn location for the projectile.
		FRotator SpawnRotation = ProjectileSpawn->GetComponentRotation(); // Sets the spawn rotation for the projectile.
		ABullet* TempBullet = GetWorld()->SpawnActor<ABullet>(BulletClass, SpawnLocation, SpawnRotation); // Spawns in the projectile.
	}
}

