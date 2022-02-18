// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTS_PlayerPosition.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UBTS_PlayerPosition : public UBTService_BlackboardBase
{
	GENERATED_BODY()

protected:
	// Called every frame (overwrites the basic tick function).
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
