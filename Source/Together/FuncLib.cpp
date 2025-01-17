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

AActor* UFuncLib::SpawnActorWithZCorrection(AActor* target, TSubclassOf<class AActor> actorclass, FVector loc, FRotator rot)
{
	FActorSpawnParameters spawnpar;
	spawnpar.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AActor* object = target->GetWorld()->SpawnActor<AActor>(actorclass, loc, rot, spawnpar);
	float zcor = (object->GetActorLocation() - object->FindComponentByClass<UStaticMeshComponent>()->GetSocketLocation("Loc_under")).Z;

	object->SetActorLocation(FVector(loc.X, loc.Y, loc.Z + zcor));

	return object;
}

AArea* UFuncLib::GetAreaClass(AActor* Actor, EArea FindAreaEnum, int index, bool random)
{
	UGameInstance* gminst = Actor->GetGameInstance();
	TArray<AArea*> areas;
	TArray<AArea*> sel_areas;

	if (gminst)
	{
		areas = Cast<UGameInst>(gminst)->Areas;
	}
	else { print("Game Instance Not Found!"); }

	for (AArea* a : areas)
	{
		if (a->AreaEnum == FindAreaEnum)
		{
			sel_areas.Add(a);
		}
	}

	if (random)
	{
		index = FMath::RandRange(0, sel_areas.Num() - 1);
	}

	if (sel_areas.Num() != 0)
	{
		return sel_areas[index];
	}
	else
	{
		return nullptr;
	}
}

TArray<AArea*> UFuncLib::GetAreaClasses(AActor* Actor, EArea FindAreaEnum)
{
	UGameInstance* gminst = Actor->GetGameInstance();
	TArray<AArea*> areas;
	TArray<AArea*> sel_areas;

	if (gminst)
	{
		areas = Cast<UGameInst>(gminst)->Areas;
	}
	else { print("Game Instance Not Found!"); }

	for (AArea* a : areas)
	{
		if (a->AreaEnum == FindAreaEnum)
		{
			sel_areas.AddUnique(a);
		}
	}

	return sel_areas;
}

AArea* UFuncLib::GetAreaClassFromVector(AActor* Actor, FVector vector)
{
	UGameInstance* gminst = Actor->GetGameInstance();
	TArray<AArea*> areas;
	TArray<AArea*> sel_areas;

	if (gminst)
	{
		areas = Cast<UGameInst>(gminst)->Areas;
	}
	else { print("Game Instance Not Found!"); }

	for (AArea* a : areas)
	{
		if (isVectorInArea(vector, a))
		{
			return a;
		}
	}

	return nullptr;
}

float UFuncLib::GetSoundStrength(float stimulus_strength, FVector impulser, FVector receiver, float multiplier)
{
	return multiplier * stimulus_strength * (1 / (FVector::Distance(impulser, receiver) / 10000));
}

bool UFuncLib::isVectorInArea(FVector vector, AArea* area)
{
	FVector p1, p2;
	area->GetXYZPoint(p1, p2);

	if (p1.X <= vector.X && vector.X <= p2.X)
	{
		if (p1.Y <= vector.Y && vector.Y <= p2.Y)
		{
			if (p1.Z <= vector.Z && vector.Z <= p2.Z)
			{
				return true;
			}
		}
	}

	return false;
}
