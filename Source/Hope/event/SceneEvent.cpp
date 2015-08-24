#include "Hope.h"
#include "SceneEvent.h"
#include "manager/SceneManager.h"
#include "GamePlayerController.h"
#include "scene/GameScene.h"

USceneEvent::USceneEvent(const FObjectInitializer& ObjectInitializer)
    : TransInScene(nullptr)
    , SceneEventEnum(ESceneEvent::INIT)
{
}
USceneEvent::~USceneEvent(){}


UGameScene* USceneEvent::GetTransInScene(){
    return TransInScene;
}

void USceneEvent::SetTransInScene(UGameScene* pTransInScene){
    checkf(pTransInScene, TEXT("SceneEvent::SetTransInScene(nullptr)"));
    TransInScene = pTransInScene;
}


void USceneEvent::Execute(){

    if (GetSceneEventEnum() == ESceneEvent::INIT){
        auto gameController = USceneManager::GetInstance()->GetGameController();
        gameController->DisableInput(gameController);
        this->SetSceneEventEnum(ESceneEvent::TRANS_OUT_CURRENT);

    } 
}


void USceneEvent::OnTransOutFinished(){
    auto eSceneEventEnum = GetSceneEventEnum();
    if (eSceneEventEnum == ESceneEvent::WAIT_TRANS_OUT_CURRENT){
        this->SetSceneEventEnum(ESceneEvent::TRANS_IN_NEXT);
    }else{
        ensureMsgf(false, TEXT("oops! SceneEvent::OnTransOutFinished() %d"), eSceneEventEnum);
    }
}
void USceneEvent::OnTransInFinished(){
    auto eSceneEventEnum = GetSceneEventEnum();
    if (eSceneEventEnum == ESceneEvent::WAIT_TRANS_IN_NEXT){
        this->SetSceneEventEnum(ESceneEvent::FINISHED);

        auto transInScene = GetTransInScene();
        if (transInScene){
            transInScene->OnSceneVisible();
        }
        USceneManager::GetInstance()->SetCurrentScene(transInScene);
        
        USceneManager::GetInstance()->TryGarbageCollection();
       
    }else{
        ensureMsgf(false, TEXT("oops! SceneEvent::OnTransInFinished() %d"), eSceneEventEnum);
    }
   
}
