// Fill out your copyright notice in the Description page of Project Settings.

#include "Hope.h"
#include "HopeGameMode.h"
#include "GamePlayerController.h"
AHopeGameMode::AHopeGameMode(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

    PlayerControllerClass = AGamePlayerController::StaticClass();
}
void AHopeGameMode::StartPlay(){
    Super::StartPlay();




}

 
/*// Header
UCLASS()
class ACameraController : public AActor
{
    GENERATED_UCLASS_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "View Target")
        ACameraActor* ViewTarget;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Controller")
        APlayerController* PlayerController;

    virtual void BeginPlay() override;
};

// Source
ACameraController::ACameraController(const class FPostConstructInitializeProperties& PCIP)
    : Super(PCIP)
{
}

void ACameraController::BeginPlay()
{
    Super::BeginPlay();

    this->PlayerController = this->GetWorld()->GetFirstPlayerController();
    if (this->PlayerController && this->ViewTarget)
    {
        this->PlayerController->SetViewTarget(this->ViewTarget);
    }
}*/