#include "Hope.h"
#include "GameWidget.h"

#include "WidgetAnimation.h"
#include "MovieScene.h"

UGameWidget::UGameWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer){

}

void UGameWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation){
    if (OnAnimationFinishedCallback){
        if (Animation){
            OnAnimationFinishedCallback(Animation->MovieScene->GetFName().ToString());
        }
    }
    UE_LOG(LogHope, Log, TEXT(" UGameWidget::OnAnimationFinished_Implementation"));
}




USceneWidget::USceneWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer){

}

void USceneWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation){
    Super::OnAnimationFinished_Implementation(Animation);
   // auto movieScene = Animation->MovieScene;
    //movieScene->GetName();

}


