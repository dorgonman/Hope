#include "Hope.h"
#include "scene/GameScene.h"

// include
#include "Blueprint/UserWidget.h"
#include "UMG.h"

#include "WidgetAnimation.h"
#include "Engine/LocalPlayer.h"
#include "Engine/GameInstance.h"
#include "MovieScene.h"
#include "GamePlayerController.h"


UGameScene::UGameScene(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    //static ConstructorHelpers::FClassFinder<UUserWidget> PutNameHere(TEXT("/Game/UMG/TitleScene/TitleSceneWBP"));
  //  if (PutNameHere.Class) {
        //SceneWidgetClass = PutNameHere.Class;
   // }
}

void UGameScene::SetSceneWidgetClass(const TCHAR* widgetPath){
    ConstructorHelpers::FClassFinder<UUserWidget> PutNameHere(widgetPath);
    if (PutNameHere.Class) {
        SceneWidgetClass = PutNameHere.Class;
    }
}

UUserWidget* UGameScene::GetSceneWidget(){ return SceneWidget; };

void UGameScene::Tick(float dt){


}

void UGameScene::OnEnter(AGamePlayerController* pController){
    //initRequest
    //initUI && execute animation

    //static ConstructorHelpers::FClassFinder<UUserWidget> PutNameHere(TEXT("/Game/UMG/TitleScene/TitleSceneWBP"));
    // if (PutNameHere.Class) {
    // TitleSceneWidgetClass = PutNameHere.Class;

    // }

    if (SceneWidgetClass){
        //auto playerController = UGameplayStatics::GetPlayerController(GEngine->GetWorld(), 0);
        SceneWidget = CreateWidget<UUserWidget>(pController, SceneWidgetClass);
        if (SceneWidget){
            //let add it to the view port
            SceneWidget->AddToViewport();
        }
    }

    //onLoadUILayer, assign value

    //if (TitleSceneWidgetClass) // Check if the Asset is assigned in the blueprint.
    //{
    //    // Create the widget and store it.
    //    TitleSceneWidget = CreateWidget<UUserWidget>(this, TitleSceneWidgetClass);

    //    // now you can use the widget directly since you have a referance for it.
    //    // Extra check to  make sure the pointer holds the widget.
    //    if (TitleSceneWidget)
    //    {
    //        //let add it to the view port
    //        TitleSceneWidget->AddToViewport();
    //    }
    //    UButton* btnStart = (UButton*)TitleSceneWidget->GetWidgetFromName(TEXT("BTN_START"));
    //    //if (btnStart)
    //    // btnStart->OnClicked.AddDynamic(this, &AMyPlayerController::StartGame);



    //    UWidgetBlueprintGeneratedClass* BGClass = Cast<UWidgetBlueprintGeneratedClass>(TitleSceneWidget->GetClass());
    //    if (BGClass){
    //        for (UWidgetAnimation* Animation : BGClass->Animations)
    //        {
    //            if (Animation->MovieScene)
    //            {

    //                UE_LOG(LogHope, Log, TEXT("test:%s"), *Animation->MovieScene->GetFName().ToString());
    //                // Find property with the same name as the template and assign the new widget to it.
    //                /* UObjectPropertyBase* Prop = FindField<UObjectPropertyBase>(WidgetBlueprintClass, Animation->MovieScene->GetFName());
    //                if (Prop)
    //                {
    //                Prop->SetObjectPropertyValue_InContainer(UserWidget, Anim);
    //                }*/
    //                //num =0 == loop
    //                //const UWidgetAnimation* InAnimation, float StartAtTime, int32 NumberOfLoops, EUMGSequencePlayMode::Type PlayMode
    //                TitleSceneWidget->PlayAnimation(Animation, 0.0F, 1);
    //            }
    //        }
    //    }


    //}
}

void UGameScene::OnExit(){


}


/*void UGameScene::OnSceneVisible(){

}
void UGameScene::OnSceneDisable(){


}*/