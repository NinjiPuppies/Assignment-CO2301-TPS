// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_PatrolArea.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UBTT_PatrolArea : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
protected:
	// Called to execute the patrol area task which determines the next spot for the ai to move to (overwrites the basic execute task function).
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:

	// Stores the radius for the ai to patrol.
	UPROPERTY(EditAnywhere)
		float PatrolRadius = 2500.0f;
};
