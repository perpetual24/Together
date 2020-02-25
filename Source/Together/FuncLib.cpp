// Fill out your copyright notice in the Description page of Project Settings.

#include "FuncLib.h"
#include <Runtime/Engine/Classes/Engine/Engine.h>

FVector UFuncLib::GetActorDir(AActor* target, EDirection dir)
{
	FVector dirvec;

	switch (dir)
	{
	case EDirection::Forward:
		dirvec = target->GetActorForwardVector();
	case EDirection::Backward:
		dirvec = -(target->GetActorForwardVector());
	case EDirection::Right:
		dirvec = target->GetActorRightVector();
	case EDirection::Left:
		dirvec = -(target->GetActorRightVector());
	case EDirection::Up:
		dirvec = target->GetActorUpVector();
	case EDirection::Down:
		dirvec = -(target->GetActorUpVector());
	default:
		dirvec = target->GetActorForwardVector();
	}

	return dirvec;
}

FHitResult UFuncLib::LineTraceWithDir(AActor* target, EDirection dir, int dist)
{
	FHitResult TraceHitResult;
	FVector dirvec = UFuncLib::GetActorDir(target, dir);
	target->GetWorld()->LineTraceSingleByChannel(TraceHitResult, target->GetActorLocation(), target->GetActorLocation() + dirvec * dist, ECollisionChannel::ECC_Visibility);

	return TraceHitResult;
}

void UFuncLib::PlayFootstepSound(AActor* target, float volume)
{
	auto surface = Cast<UGameInst>(GEngine->GetWorld()->GetGameInstance())->Surface;
	UAudioComponent* audiocomp = target->FindComponentByClass<UAudioComponent>();

	UPhysicalMaterial* physicsmat = UFuncLib::LineTraceWithDir(target, EDirection::Down, 150).PhysMaterial.Get();
	int index = surface.Find(physicsmat);

	audiocomp->SetBoolParameter("step_play", true);
	audiocomp->SetFloatParameter("step_volume", volume);
	audiocomp->SetIntParameter("floor", index);
	audiocomp->SetBoolParameter("IsMale", true);
	
	audiocomp->Play();
}