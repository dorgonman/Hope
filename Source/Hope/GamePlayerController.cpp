// Fill out your copyright notice in the Description page of Project Settings.

#include "Hope.h"
#include "GamePlayerController.h"


AGamePlayerController::AGamePlayerController(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , FixedViewTarget(nullptr)
{

    //FixedViewTarget
   // PlayerControllerClass = AGamePlayerController::StaticClass();
   


}


void AGamePlayerController::PrintAllObjectsNamesAndClasses()
{
   /* for (TObjectIterator<UObject> Itr; Itr; ++Itr)
    {
        auto name = Itr->GetName();
        auto desc = Itr->GetClass()->GetDesc();

        //UE_LOG(LogHope, Log, TEXT("test:%s"), name.);
        //UE_LOG(LogHope, Log, TEXT("test:%s"), Itr->GetClass()->GetDesc());
        ClientMessage(Itr->GetName());
        ClientMessage(Itr->GetClass()->GetDesc());
    }*/


    for (TActorIterator<ACameraActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        UE_LOG(LogHope, Log, TEXT("GetName:%s"), *ActorItr->GetName());
        UE_LOG(LogHope, Log, TEXT("GetDesc:%s"), *ActorItr->GetClass()->GetDesc());
        UE_LOG(LogHope, Log, TEXT("GetActorLabel:%s"), *ActorItr->GetActorLabel());
        UE_LOG(LogHope, Log, TEXT("GetFName:%s"), *ActorItr->GetClass()->GetFName().GetPlainNameString());

        ClientMessage(ActorItr->GetName());
        ClientMessage(ActorItr->GetActorLocation().ToString());
    }
}



void AGamePlayerController::BeginPlay(){
    Super::BeginPlay();
    //PrintAllObjectsNamesAndClasses();

    for (TActorIterator<ACameraActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        auto objectName = ActorItr->GetName();
        if (FString("MainCameraActor") == objectName){
            FixedViewTarget = *ActorItr;
            break;
        }
    }
    
    SetViewTarget(this->FixedViewTarget);
}


void AGamePlayerController::Tick(float DeltaSeconds){
  //  PrintAllObjectsNamesAndClasses();
    /*FVector CameraLoc;
    FRotator CameraRot;
    GetActorEyesViewPoint(CameraLoc, CameraRot);

    // calculate the camera position
    CameraLoc += CameraLoc.ForwardVector * 10.0f;

    FixedViewTarget->SetActorLocation(CameraLoc, false, NULL);*/
}