// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInst.h"

void UGameInst::InitiateAreas()
{
	TArray<AActor*> area_actors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AArea::StaticClass(), area_actors);
	
	for (AActor* actor : area_actors)
	{
		auto area = Cast<AArea>(actor);

		Areas.Add(area);

		if (halls_enum.Contains(area->AreaEnum))
		{
			Halls.Add(area);
		}
		else
		{
			Rooms.Add(area);
		}
	}
}
