#include "Hope.h"
#include "scene/GameScene.h"

// include

#include "UMG.h"

#include "WidgetAnimation.h"
#include "Engine/LocalPlayer.h"
#include "Engine/GameInstance.h"
#include "MovieScene.h"
#include "GamePlayerController.h"


USceneWidget::USceneWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer){

}

void USceneWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation){

}





UGameScene::UGameScene(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    //static ConstructorHelpers::FClassFinder<UUserWidget> PutNameHere(TEXT("/Game/UMG/TitleScene/TitleSceneWBP"));
  //  if (PutNameHere.Class) {
        //SceneWidgetClass = PutNameHere.Class;
   // }
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
            //let add it to the view port
            SceneWidget->AddToViewport();
        }
    }
    //onLoadUILayer, assign value
}

void UGameScene::OnExit(){


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