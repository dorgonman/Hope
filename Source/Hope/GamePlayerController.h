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
    virtual void BeginPlay() override;
    // Called every frame
    virtual void Tick(float DeltaSeconds) override;
    void PrintAllObjectsNamesAndClasses();

    // Reference UMG Asset in the Editor
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
    TSubclassOf<class UUserWidget> TitleSceneWidgetClass;
private:
    ACameraActor* MainCameraActor;
private:
    // Variable to hold the widget After Creating it.
    UUserWidget* TitleSceneWidget;
};
