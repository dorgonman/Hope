// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"



/**
 * 
 */
UCLASS()
class HOPE_API AGamePlayerController : public APlayerController
{
    GENERATED_BODY()
	
public:
    AGamePlayerController(const FObjectInitializer& ObjectInitializer);
    virtual ~AGamePlayerController();
    virtual void BeginPlay() override;
    // Called every frame
    virtual void Tick(float DeltaSeconds) override;
    void PrintAllObjectsNamesAndClasses();
private:
    UPROPERTY()
    ACameraActor* MainCameraActor;
private:

};
