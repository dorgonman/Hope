#include "Hope.h"
#include "scene/HomeScene.h"
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
UHomeScene::UHomeScene(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

    
    this->SetSceneWidgetClass(TEXT("/Game/UMG/HomeScene/HomeSceneWBP"));
    
}

UHomeScene::~UHomeScene(){


}

void UHomeScene::Tick(float dt){
    Super::Tick(dt);


}

void UHomeScene::OnEnter(AGamePlayerController* pController){
    Super::OnEnter(pController);
    //initRequest
    //initUI && execute animation

}

void UHomeScene::OnExit(){


}

void UHomeScene::OnSceneVisible(){
    Super::OnSceneVisible();
    UButton* btnStart = dynamic_cast<UButton*>(GetSceneWidget()->GetWidgetFromName(TEXT("BTN_START")));
    if (btnStart){
        btnStart->OnClicked.AddDynamic(this, &UHomeScene::StartGame);
    }else{
        checkf(btnStart, TEXT("UHomeScene::OnSceneVisible btnStart nullptr"));

    }



}
void UHomeScene::OnSceneDisable(){
    Super::OnSceneDisable();
  
    //GetSceneWidget()->GetRootWidget();

}




void UHomeScene::StartGame(){
    UE_LOG(LogHope, Log, TEXT("StartGame:"));
    USceneManager::GetInstance()->ChangeScene<UTitleScene>();
}



void UHomeScene::OnAnimationFinished(const FString& animeName){
    Super::OnAnimationFinished(animeName);


  

}