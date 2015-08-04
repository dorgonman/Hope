#include "Hope.h"
#include "scene/GameScene.h"

// include

#include "UMG.h"

#include "WidgetAnimation.h"
#include "Engine/LocalPlayer.h"
#include "Engine/GameInstance.h"
#include "MovieScene.h"
#include "GamePlayerController.h"

#include "widget/GameWidget.h"
#include "event/SceneEvent.h"


static FString BEGIN_ENTER = "__begin_enter__";

static FString BEGIN_EXIT = "__begin_exit__";


UGameScene::UGameScene(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    //static ConstructorHelpers::FClassFinder<UUserWidget> PutNameHere(TEXT("/Game/UMG/TitleScene/TitleSceneWBP"));
  //  if (PutNameHere.Class) {
        //SceneWidgetClass = PutNameHere.Class;
   // }
}


UGameScene::~UGameScene(){

}

void UGameScene::SetSceneWidgetClass(const TCHAR* widgetPath){
    ConstructorHelpers::FClassFinder<USceneWidget> PutNameHere(widgetPath);
    if (PutNameHere.Class) {
        SceneWidgetClass = PutNameHere.Class;
    }
}

USceneWidget* UGameScene::GetSceneWidget(){ return SceneWidget; };

void UGameScene::Tick(float dt){


}

void UGameScene::OnEnter(AGamePlayerController* pController){
    //initRequest
    //initUI && execute animation

    if (SceneWidgetClass){
        //auto playerController = UGameplayStatics::GetPlayerController(GEngine->GetWorld(), 0);
        SceneWidget = CreateWidget<USceneWidget>(pController, SceneWidgetClass);
        if (SceneWidget){

            SceneWidget->OnAnimationFinishedDelegate.BindUObject(this, &UGameScene::OnAnimationFinished);

            //let add it to the view port
            SceneWidget->AddToViewport();
        }
    }
    //onLoadUILayer, assign value
}


void UGameScene::OnSceneVisible(){
    UE_LOG(LogHope, Log, TEXT("UGameScene::OnSceneVisible"));
}
void UGameScene::OnSceneDisable(){
    UE_LOG(LogHope, Log, TEXT("UGameScene::OnSceneDisable"));
    GetSceneWidget()->WidgetTree->ForEachWidget([&](UWidget* Widget) {
        UButton* pBtn = dynamic_cast<UButton*>(Widget);
        if (pBtn){
            pBtn->OnClicked.Clear();
        }
        UE_LOG(LogHope, Log, TEXT("OnSceneDisable:%s"), *Widget->GetFName().ToString());
    });

}

void UGameScene::OnExit(){

    if (SceneWidget){
        SceneWidget->RemoveFromViewport();
    }
}

UWidgetAnimation* UGameScene::GetWidgetAnimation(const FString& animeName){

    UWidgetBlueprintGeneratedClass* BGClass = Cast<UWidgetBlueprintGeneratedClass>(GetSceneWidget()->GetClass());
    if (BGClass){
        for (UWidgetAnimation* Animation : BGClass->Animations)
        {
            if (Animation->MovieScene)
            {

                UE_LOG(LogHope, Log, TEXT("test:%s"), *Animation->MovieScene->GetFName().ToString());
                if (animeName.Equals(Animation->MovieScene->GetFName().ToString())){
                    UE_LOG(LogHope, Log, TEXT("Find Animation:%s"), *Animation->MovieScene->GetFName().ToString());
                    return Animation;
                }

                // Find property with the same name as the template and assign the new widget to it.
                /* UObjectPropertyBase* Prop = FindField<UObjectPropertyBase>(WidgetBlueprintClass, Animation->MovieScene->GetFName());
                if (Prop)
                {
                Prop->SetObjectPropertyValue_InContainer(UserWidget, Anim);
                }*/
               
            }
        }
    }
    return nullptr;
}
/*void UGameScene::OnSceneVisible(){

}
void UGameScene::OnSceneDisable(){


}*/

void UGameScene::OnAnimationFinished(const FString& animeName){
    UE_LOG(LogHope, Log, TEXT("UGameScene::onAnimationFinished"));


    if (animeName.Equals(BEGIN_ENTER)){
        UE_LOG(LogHope, Log, TEXT("UTitleScene::onAnimationFinished begin_enter"));
        SceneEventListenerWeakPtr.Pin()->OnTransInFinished();
    }else if (animeName.Equals(BEGIN_EXIT)){
        UE_LOG(LogHope, Log, TEXT("UTitleScene::onAnimationFinished begin_exit"));
        SceneEventListenerWeakPtr.Pin()->OnTransOutFinished();
    }
}


void UGameScene::PlayTransOutAnimation(const TSharedPtr<SceneEvent>& pSceneEvent){

    SceneEventListenerWeakPtr = pSceneEvent;
    auto animeName = FString(BEGIN_EXIT);
    auto animation = GetWidgetAnimation(animeName);
    if (animation){
        auto sceneWidget = GetSceneWidget();
        sceneWidget->PlayAnimation(animation, 0.0F, 1);
     
    }else{
        OnAnimationFinished(BEGIN_EXIT);
    }

   
}


void UGameScene::PlayTransInAnimation(const TSharedPtr<SceneEvent>& pSceneEvent){

    SceneEventListenerWeakPtr = pSceneEvent;
    auto animeName = FString(BEGIN_ENTER);
    auto animation = GetWidgetAnimation(animeName);
    if (animation){
        auto sceneWidget = GetSceneWidget();
        sceneWidget->PlayAnimation(animation, 0.0F, 1);
    }else{
        OnAnimationFinished(BEGIN_ENTER);
    }

}