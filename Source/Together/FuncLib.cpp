// Fill out your copyright notice in the Description page of Project Settings.

#include "FuncLib.h"
#include "DrawDebugHelpers.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, text)

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
	FVector actorloc = target->GetActorLocation();
	FVector dirvec = UFuncLib::GetActorDir(target, dir);
	target->GetWorld()->LineTraceSingleByChannel(TraceHitResult, actorloc, FVector(actorloc.X + dirvec.X * dist, actorloc.Y + dirvec.Y * dist, actorloc.Z + dirvec.Z * dist), ECollisionChannel::ECC_Visibility);

	return TraceHitResult;
}

void UFuncLib::PlayFootstepSound(AActor* target, UPhysicalMaterial* phymat, float volume)
{
	TArray<UPhysicalMaterial*> surface;
	UGameInstance* gminst = target->GetGameInstance();

	if (gminst)
	{
		surface = Cast<UGameInst>(gminst)->Surface;
	}
	else { print("Game Instance Not Found!"); }

	int index = surface.Find(phymat);

	UAudioComponent* audiocomp = target->FindComponentByClass<UAudioComponent>();

	if (audiocomp)
	{
		audiocomp->SetBoolParameter("step_play", true);
		audiocomp->SetFloatParameter("step_volume", volume);
		audiocomp->SetIntParameter("floor", index);
		audiocomp->SetBoolParameter("IsMale", true);

		audiocomp->Play();
	}
	else { print("AudioComponent Not Found!"); }
}