// Fill out your copyright notice in the Description page of Project Settings.

#include "Hope.h"
#include "GamePlayerController.h"
#include "camera/MainCameraActor.h"
#include "UMG.h"
#include "WidgetAnimation.h"
#include "Engine/LocalPlayer.h"
#include "Engine/GameInstance.h"
#include "MovieScene.h"
AGamePlayerController::AGamePlayerController(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , MainCameraActor(nullptr)
{
    this->bShowMouseCursor = true;
    this->bEnableClickEvents = true;
    this->bEnableMouseOverEvents = true;
    //UGameplayStatics::GetPlayerController
    //GetWorld()->AddController(this);

    static ConstructorHelpers::FClassFinder<UUserWidget> PutNameHere(TEXT("/Game/UMG/TitleScene/TitleSceneWBP"));
    if (PutNameHere.Class) {
        TitleSceneWidgetClass = PutNameHere.Class;

    }
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
    //PrintAllObjectsNamesAndClasses();

    for (TActorIterator<ACameraActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        auto objectName = ActorItr->GetName();
        auto classDesc = ActorItr->GetClass()->GetDesc();
        UE_LOG(LogHope, Log, TEXT("GetName:%s"), *objectName);
        //UE_LOG(LogHope, Log, TEXT("classDesc:%s"), *classDesc);
        //UE_LOG(LogHope, Log, TEXT("GetActorLabel:%s"), *ActorItr->GetActorLabel());
        //UE_LOG(LogHope, Log, TEXT("GetFName:%s"), *ActorItr->GetClass()->GetFName().GetPlainNameString());

        if (FString("MainCamera") == objectName){
            this->MainCameraActor = *ActorItr;
            break;
        }
    }
    ensureMsg(nullptr != MainCameraActor , TEXT("MainCamera can't find"));
    //check((nullptr != MainCameraActor) && "Did you forget to call Init()?");
    //SetViewTarget(this->MainCameraActor);
  



    if (TitleSceneWidgetClass) // Check if the Asset is assigned in the blueprint.
    {
        // Create the widget and store it.
        TitleSceneWidget = CreateWidget<UUserWidget>(this, TitleSceneWidgetClass);

        // now you can use the widget directly since you have a referance for it.
        // Extra check to  make sure the pointer holds the widget.
        if (TitleSceneWidget)
        {
            //let add it to the view port
            TitleSceneWidget->AddToViewport();
        }
        UButton* btnStart = (UButton*)TitleSceneWidget->GetWidgetFromName(TEXT("BTN_START"));
        //if (btnStart)
           // btnStart->OnClicked.AddDynamic(this, &AMyPlayerController::StartGame);



        UWidgetBlueprintGeneratedClass* BGClass = Cast<UWidgetBlueprintGeneratedClass>(TitleSceneWidget->GetClass());
        if (BGClass){
            for (UWidgetAnimation* Animation : BGClass->Animations)
            {
                if (Animation->MovieScene)
                {

                    UE_LOG(LogHope, Log, TEXT("test:%s"), *Animation->MovieScene->GetFName().ToString());
                    // Find property with the same name as the template and assign the new widget to it.
                    /* UObjectPropertyBase* Prop = FindField<UObjectPropertyBase>(WidgetBlueprintClass, Animation->MovieScene->GetFName());
                    if (Prop)
                    {
                    Prop->SetObjectPropertyValue_InContainer(UserWidget, Anim);
                    }*/
                    //num =0 == loop
                    //const UWidgetAnimation* InAnimation, float StartAtTime, int32 NumberOfLoops, EUMGSequencePlayMode::Type PlayMode
                    TitleSceneWidget->PlayAnimation(Animation, 0.0F, 1);
                }
            }
        }

     
    }
   // this->MainCameraActor-> = ECameraProjectionMode::Orthographic;
    
}


void AGamePlayerController::Tick(float DeltaSeconds){

    if (IsInputKeyDown(EKeys::A)){
        UE_LOG(LogHope, Log, TEXT("EKeys::A"));
    }else if (IsInputKeyDown(EKeys::LeftMouseButton) || 
             IsInputKeyDown(EKeys::TouchKeys[1])){
        //UE_LOG(LogHope, Log, TEXT("EKeys::LeftMouseButton || EKeys::TouchKeys[1]"));
       // ClientMessage("EKeys::LeftMouseButton");
    }else if (IsInputKeyDown(EKeys::MouseY)){

        UE_LOG(LogHope, Log, TEXT("EKeys::MouseY"));

    }
}