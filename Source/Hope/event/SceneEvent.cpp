#include "Hope.h"
#include "SceneEvent.h"
#include "manager/SceneManager.h"
#include "GamePlayerController.h"
#include "scene/GameScene.h"
//=============begin GameEvent==========================
GameEvent::GameEvent(){

}
GameEvent::~GameEvent(){

}

//==============end GameEvent===========================
SceneEvent::SceneEvent()
    : TransInScene(nullptr)
    , SceneEventEnum(ESceneEvent::INIT)
{
}
SceneEvent::~SceneEvent(){}


UGameScene* SceneEvent::GetTransInScene(){ 
    return TransInScene;
}

void SceneEvent::SetTransInScene(UGameScene* pTransInScene){
    checkf(pTransInScene, TEXT("SceneEvent::SetTransInScene(nullptr)"));
    if (TransInScene){
        TransInScene->BeginDestroy();
    }
    TransInScene = pTransInScene;
}


void SceneEvent::Execute(){

    if (GetSceneEventEnum() == ESceneEvent::INIT){
        auto gameController = SceneManager::GetInstance()->GetGameController();
        gameController->DisableInput(gameController);
        this->SetSceneEventEnum(ESceneEvent::TRANS_OUT_CURRENT);

    } /*else if (GetSceneEventEnum() == ESceneEvent::TRANS_OUT_CURRENT){
  
        auto pCurrentScene = SceneManager::GetInstance()->GetCurrentScene();
        if (pCurrentScene){
            pCurrentScene->OnSceneDisable();
        }
        this->SetSceneEventEnum(ESceneEvent::TRANS_IN_NEXT);
    }else if (GetSceneEventEnum() == ESceneEvent::TRANS_IN_NEXT){
        auto pCurrentScene = SceneManager::GetInstance()->GetCurrentScene();
        if (pCurrentScene){
            pCurrentScene->OnSceneDisable();
        }
    
        this->SetSceneEventEnum(ESceneEvent::FINISHED);
    }else if (GetSceneEventEnum() == ESceneEvent::FINISHED){

    }*/
}


void SceneEvent::OnTransOutFinished(){
    if (GetSceneEventEnum() == ESceneEvent::WAIT_TRANS_OUT_CURRENT){
        this->SetSceneEventEnum(ESceneEvent::TRANS_IN_NEXT);
    }else{
        ensureMsg(false, TEXT("oops! SceneEvent::OnTransOutFinished()"));
    }
}
void SceneEvent::OnTransInFinished(){

    if (GetSceneEventEnum() == ESceneEvent::WAIT_TRANS_IN_NEXT){
        this->SetSceneEventEnum(ESceneEvent::FINISHED);

        auto transInScene = GetTransInScene();
        if (transInScene){
            transInScene->OnSceneVisible();
        }
    }else{
        ensureMsg(false, TEXT("oops! SceneEvent::OnTransInFinished()"));
    }
   
}

//=============begin ChangeSceneEvent==========================

ChangeSceneEvent::ChangeSceneEvent(){

}

ChangeSceneEvent::~ChangeSceneEvent(){

}



void  ChangeSceneEvent::Execute(){
    SceneEvent::Execute();
    if (GetSceneEventEnum() == ESceneEvent::TRANS_OUT_CURRENT){
        this->SetSceneEventEnum(ESceneEvent::WAIT_TRANS_OUT_CURRENT);
        auto pCurrentScene = SceneManager::GetInstance()->GetCurrentScene();
        if (pCurrentScene){
            pCurrentScene->OnSceneDisable();
            pCurrentScene->PlayTransOutAnimation(SharedThis(this));   
        }else{
            OnTransOutFinished();
        }

    }else if (GetSceneEventEnum() == ESceneEvent::TRANS_IN_NEXT){
        this->SetSceneEventEnum(ESceneEvent::WAIT_TRANS_IN_NEXT);
        auto gameController = SceneManager::GetInstance()->GetGameController();
        auto transInScene = GetTransInScene();
        if (transInScene){
            transInScene->OnEnter(gameController);
            transInScene->PlayTransInAnimation(SharedThis(this));
            
        }else{
            OnTransInFinished();
        }
    }


}

//==============end ChangeSceneEvent===========================


