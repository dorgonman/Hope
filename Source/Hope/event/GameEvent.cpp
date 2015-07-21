#include "Hope.h"
#include "GameEvent.h"
#include "manager/SceneManager.h"
#include "GamePlayerController.h"
#include "scene/GameScene.h"
//=============begin GameEvent==========================
GameEvent::GameEvent(){

}
GameEvent::~GameEvent(){

}

//==============end GameEvent===========================
SceneEvent::SceneEvent(){}
SceneEvent::~SceneEvent(){}

void SceneEvent::Execute(){


    if (GetSceneEventEnum() == ESceneEvent::INIT){
        auto gameController = SceneManager::GetInstance()->GetGameController();
        gameController->DisableInput(gameController);
        auto pCurrentScene = SceneManager::GetInstance()->GetCurrentScene();
        if (pCurrentScene){
            pCurrentScene->OnSceneDisable();
        }
        this->SetSceneEventEnum(ESceneEvent::TRANS_OUT_CURRENT);

    }
}


//=============begin ChangeSceneEvent==========================

/*ChangeSceneEvent::ChangeSceneEvent(){

}

ChangeSceneEvent::~ChangeSceneEvent(){

}*/


//==============end ChangeSceneEvent===========================


