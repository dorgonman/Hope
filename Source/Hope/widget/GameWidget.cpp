#include "Hope.h"
#include "GameWidget.h"

#include "WidgetAnimation.h"
#include "MovieScene.h"

UGameWidget::UGameWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer){

}

void UGameWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation){
    UE_LOG(LogHope, Log, TEXT(" UGameWidget::OnAnimationFinished_Implementation"));
    checkf(Animation, TEXT("UGameWidget::OnAnimationFinished_Implementation Animation is nullptr"));

    if (Animation){
        checkf(OnAnimationFinishedDelegate.IsBound(), TEXT("UGameWidget::OnAnimationFinished_Implementation callback not bound"));

        if (OnAnimationFinishedDelegate.IsBound()){
            OnAnimationFinishedDelegate.ExecuteIfBound(Animation->MovieScene->GetFName().ToString());
        }else{
            UE_LOG(LogHope, Log, TEXT(" UGameWidget::OnAnimationFinished_Implementation oops2!"));
          
        }
    }
    else{
        UE_LOG(LogHope, Log, TEXT(" UGameWidget::OnAnimationFinished_Implementation oops!"));
    
    }
    
   // if (OnAnimationFinishedCallback){
        //if (Animation){
            //OnAnimationFinishedCallback(Animation->MovieScene->GetFName().ToString());
       // }
   // }
  
}




USceneWidget::USceneWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer){

}

void USceneWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation){
    Super::OnAnimationFinished_Implementation(Animation);
   // auto movieScene = Animation->MovieScene;
    //movieScene->GetName();

}


