// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"



#include "BBPC.generated.h"

class UInputMappingContext;


/**
 * 
 */
UCLASS()
class L231228_API ABBPC : public APlayerController
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	TObjectPtr<UInputMappingContext> DefaultINC;

	virtual void BeginPlay() override;
};
