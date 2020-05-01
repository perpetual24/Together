// Fill out your copyright notice in the Description page of Project Settings.


#include "FindNearHall.h"

EBTNodeResult::Type UFindNearHall::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto AIC = OwnerComp.GetAIOwner();


	return EBTNodeResult::Succeeded;
}
