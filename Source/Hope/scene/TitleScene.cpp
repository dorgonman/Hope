#include "Hope.h"
#include "scene/TitleScene.h"

// include
#include "Blueprint/UserWidget.h"
#include "UMG.h"


#include "Engine/LocalPlayer.h"
#include "Engine/GameInstance.h"
#include "MovieScene.h"
#include "GamePlayerController.h"
#include "WidgetAnimation.h"
#include "widget/GameWidget.h"

#include <functional>
/*TitleScene::TitleScene(){
    static ConstructorHelpers::FClassFinder<UUserWidget> PutNameHere(TEXT("/Game/UMG/TitleScene/TitleSceneWBP"));
    if (PutNameHere.Class) {
        SceneWidgetClass = PutNameHere.Class;
    }
}
TitleScene::~TitleScene(){

}*/
UTitleScene::UTitleScene(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

    
    this->SetSceneWidgetClass(TEXT("/Game/UMG/TitleScene/TitleSceneWBP"));
    
}

void UTitleScene::Tick(float dt){
    Super::Tick(dt);


}

void UTitleScene::OnEnter(AGamePlayerController* pController){
    Super::OnEnter(pController);
    //initRequest
    //initUI && execute animation

    UButton* btnStart = dynamic_cast<UButton*>(GetSceneWidget()->GetWidgetFromName(TEXT("BTN_START")));
    if (btnStart){
        btnStart->OnClicked.AddDynamic(this, &UTitleScene::StartGame);
    }
}
void UTitleScene::OnSceneVisible(){

}
void UTitleScene::OnExit(){


}
void UTitleScene::OnSceneDisable(){


}




void UTitleScene::StartGame(){
    UE_LOG(LogHope, Log, TEXT("StartGame:"));
}



void UTitleScene::onAnimationFinished(const UWidgetAnimation* Animation){
    Super::onAnimationFinished(Animation);


  

}