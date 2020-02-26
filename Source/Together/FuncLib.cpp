// Fill out your copyright notice in the Description page of Project Settings.

#include "FuncLib.h"
#include "DrawDebugHelpers.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, text)

void UFuncLib::PlayFootstepSound(AActor* target, UPhysicalMaterial* phymat, float volume)
{
	if (phymat)
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
	else
	{
		print("Physics Material Not found!");
	}
	
}