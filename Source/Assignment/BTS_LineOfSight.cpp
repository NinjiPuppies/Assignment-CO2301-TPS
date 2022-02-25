// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_LineOfSight.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

// Called every frame
void UBTS_LineOfSight::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	// Gets a reference to the ai controller and player.
	AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);

	// Checks if the ai can see the player.
	if (AIController->LineOfSightTo(PlayerPawn))
	{
		// If it can it will send a positive value to 'HasLineOfSight' key in order to allow the ai to chase the player.
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true);
	}
	else
	{
		// Clears the 'HasLineOfSight' key as the player cannot be seen.
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}