#include "Hope.h"
#include "SceneManager.h"
#include "UMG.h"
#include "WidgetAnimation.h"
#include "scene/TitleScene.h"
#include "GamePlayerController.h"
#include "event/SceneEvent.h"

static USceneManager* s_instance = nullptr;
USceneManager::USceneManager(const FObjectInitializer& ObjectInitializer)
    : GameController(nullptr)
    , CurrentScene(nullptr)
{

}
USceneManager::~USceneManager(){

}
USceneManager* USceneManager::GetInstance(){
    if (nullptr == s_instance){
        s_instance = NewObject<USceneManager>();
        s_instance->AddToRoot();
    }
    return s_instance;
}

void USceneManager::Destroy(){
    if (s_instance){
        s_instance->RemoveFromRoot();
        s_instance = nullptr;
    }
    //delete s_instance;
    //s_instance = nullptr;
}

void USceneManager::SetGameController(AGamePlayerController* pController) {
    GameController = pController;
    //pController->DisableInput(pController);
    //pController->EnableInput();
}


void USceneManager::SetCurrentScene(UGameScene* pCurrentScene){
    ensureMsgf(pCurrentScene, TEXT("oops! SceneManager::SetCurrentScene()"));
    if (CurrentScene){
        CurrentScene->OnExit();
    }
    CurrentScene = pCurrentScene;
}


void USceneManager::Tick(float dt){




    if (SceneEventArr.Num() > 0){
        auto pEvent = SceneEventArr[0];
        if (pEvent->IsFinished()){
            CurrentScene = pEvent->GetTransInScene();
            SceneEventArr.Remove(pEvent);
            
            UE_LOG(LogHope, Log, TEXT("SceneEventArr:%d"), SceneEventArr.Num());
        }else{
            pEvent->Execute();
        
        } 
        return;
    }

    if (CurrentScene->IsValidLowLevel()){
        CurrentScene->Tick(dt);
    }
 

}

