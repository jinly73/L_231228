// Fill out your copyright notice in the Description page of Project Settings.


#include "BBPC.h"

#include "EnhancedInputSubsystems.h"


void ABBPC::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem
		<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem && DefaultINC)
	{
		Subsystem->AddMappingContext(DefaultINC, 0);
	}

}
