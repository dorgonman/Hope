// Fill out your copyright notice in the Description page of Project Settings.

#include "Hope.h"
#include "GamePlayerController.h"
#include "camera/MainCameraActor.h"
#include "HorizonPlugin.h"
//#include "HorizonPlugin.h"
//#include "HorizonCore.h"

//#include <boost/system/config.hpp>
AGamePlayerController::AGamePlayerController(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , MainCameraActor(nullptr)
{
    this->bShowMouseCursor = true;
    this->bEnableClickEvents = true;
    this->bEnableMouseOverEvents = true;
    //UGameplayStatics::GetPlayerController
    //GetWorld()->AddController(this);
   // boost::asio::io_service io_service;
    //io_service.run();
    //horizon::HTest t1;

    //start();

}

AGamePlayerController::~AGamePlayerController(){
    
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


    for (TActorIterator<AMainCameraActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        UE_LOG(LogHope, Log, TEXT("GetName:%s"), *ActorItr->GetName());
        UE_LOG(LogHope, Log, TEXT("GetDesc:%s"), *ActorItr->GetClass()->GetDesc());
       // UE_LOG(LogHope, Log, TEXT("GetActorLabel:%s"), *ActorItr->GetActorLabel());
        UE_LOG(LogHope, Log, TEXT("GetFName:%s"), *ActorItr->GetClass()->GetFName().GetPlainNameString());

        ClientMessage(ActorItr->GetName());
        ClientMessage(ActorItr->GetActorLocation().ToString());
    }
}



void AGamePlayerController::BeginPlay(){
    Super::BeginPlay();
    //HORIZON_INFO << "TEST" << "\n" << "test2";
    //HorizonPlugin::Get();
}


void AGamePlayerController::Tick(float DeltaSeconds){


}

