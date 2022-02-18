// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_PatrolArea.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

// Called to execute the patrol area task which determines the next spot for the ai to move to.
EBTNodeResult::Type UBTT_PatrolArea::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	// Gets a reference to the ai pawn.
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AActor* AIController = OwnerComp.GetAIOwner()->GetPawn();

	// Declares the variables for the navigation system and patrol point.
	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
	FNavLocation PatrolPoint;

	// Uses the Navigation Systems 'GetRandomReachablePointInRadius' function to find a random point in the determined radius and stores it as 'patrol point'.
	NavSystem->GetRandomReachablePointInRadius(AIController->GetActorLocation(), PatrolRadius, PatrolPoint);
	
	// Sets this patrol point to the blackboard key of the same name in order to allow the ai to randomly patrol the map.
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PatrolPoint);
	return EBTNodeResult::Succeeded;
}