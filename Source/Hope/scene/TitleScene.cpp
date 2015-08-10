#include "Hope.h"
#include "scene/TitleScene.h"
#include "scene/HomeScene.h"

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

UTitleScene::~UTitleScene(){


}

void UTitleScene::Tick(float dt){
    Super::Tick(dt);


}

void UTitleScene::OnEnter(AGamePlayerController* pController){
    Super::OnEnter(pController);
    //initRequest
    //initUI && execute animation

}

void UTitleScene::OnExit(){


}

void UTitleScene::OnSceneVisible(){
    Super::OnSceneVisible();
    UButton* btnStart = dynamic_cast<UButton*>(GetSceneWidget()->GetWidgetFromName(TEXT("BTN_START")));
    if (btnStart){
        btnStart->OnClicked.AddDynamic(this, &UTitleScene::StartGame);
    }else{
        checkf(btnStart, TEXT("UTitleScene::OnSceneVisible btnStart nullptr"));
    
    }



}
void UTitleScene::OnSceneDisable(){
    Super::OnSceneDisable();
    UButton* btnStart = dynamic_cast<UButton*>(GetSceneWidget()->GetWidgetFromName(TEXT("BTN_START")));
    if (btnStart){
        btnStart->OnClicked.Clear();
    }
    //GetSceneWidget()->GetRootWidget();

}




void UTitleScene::StartGame(){
    UE_LOG(LogHope, Log, TEXT("StartGame:"));
    SceneManager::GetInstance()->ChangeScene<UHomeScene>();
}



void UTitleScene::OnAnimationFinished(const FString& animeName){
    Super::OnAnimationFinished(animeName);


  

}