// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "HopeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class HOPE_API AHopeGameMode : public AGameMode
{
    GENERATED_BODY()
	
public:
    AHopeGameMode(const FObjectInitializer& ObjectInitializer);
    
    /** Transitions to WaitingToStart and calls BeginPlay on actors. */
    virtual void StartPlay() override;

	
	
};
