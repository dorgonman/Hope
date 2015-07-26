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


//=============begin ChangeSceneEvent==========================

ChangeSceneEvent::ChangeSceneEvent(){

}

ChangeSceneEvent::~ChangeSceneEvent(){

}



void  ChangeSceneEvent::Execute(){
    SceneEvent::Execute();
    if (GetSceneEventEnum() == ESceneEvent::TRANS_OUT_CURRENT){
        auto pCurrentScene = SceneManager::GetInstance()->GetCurrentScene();
        if (pCurrentScene){
            //pCurrentScene->OnSceneDisable();
            pCurrentScene->PlayTransOutAnimation();
            this->SetSceneEventEnum(ESceneEvent::TRANS_IN_NEXT);
        }else{
            this->SetSceneEventEnum(ESceneEvent::TRANS_IN_NEXT);
        }
        

    }else if (GetSceneEventEnum() == ESceneEvent::TRANS_IN_NEXT){
        auto gameController = SceneManager::GetInstance()->GetGameController();
        GetTransInScene()->OnEnter(gameController);
        this->SetSceneEventEnum(ESceneEvent::FINISHED);
       // gameController->EnableInput(gameController);
    }


}

//==============end ChangeSceneEvent===========================


