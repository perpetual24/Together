// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLib.h"

FunctionLib::FunctionLib()
{

}

FunctionLib::~FunctionLib()
{

}

FHitResult FunctionLib::ForwardLineTrace(AActor* targetplayer, int tracedist)
{
	UCameraComponent* camera = targetplayer->FindComponentByClass<UCameraComponent>();

	FHitResult TraceHitResult;
	targetplayer->GetWorld()->LineTraceSingleByChannel(TraceHitResult, camera->GetComponentLocation(), camera->GetComponentLocation() + camera->GetForwardVector() * tracedist, ECollisionChannel::ECC_Visibility);

	return TraceHitResult;
}
