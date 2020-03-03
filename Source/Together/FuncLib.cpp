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

FVector UFuncLib::RandomVector(FVector from, FVector to)
{
	float x = FMath::RandRange(from.X, to.X);
	float y = FMath::RandRange(from.Y, to.Y);
	float z = FMath::RandRange(from.Z, to.Z);

	return FVector(x, y, z);
}

FRotator UFuncLib::RandomRotator(FRotator from, FRotator to)
{
	float yaw = FMath::RandRange(from.Yaw, to.Yaw);
	float pitch = FMath::RandRange(from.Pitch, to.Pitch);
	float roll = FMath::RandRange(from.Roll, to.Roll);

	return FRotator(pitch, yaw, roll);
}

void UFuncLib::SpawnActorWithZCorrection(AActor* target, TSubclassOf<class AActor> actorclass, FVector loc, FRotator rot)
{
	AActor* object = target->GetWorld()->SpawnActor<AActor>(actorclass, loc, rot);
	float zcor = (object->GetActorLocation() - object->FindComponentByClass<UStaticMeshComponent>()->GetSocketLocation("Loc_under")).Z;

	object->SetActorLocation(loc + zcor);
}