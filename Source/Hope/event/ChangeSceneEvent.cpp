#include "Hope.h"
#include "ChangeSceneEvent.h"
#include "manager/SceneManager.h"
#include "GamePlayerController.h"
#include "scene/GameScene.h"



UChangeSceneEvent::UChangeSceneEvent(const FObjectInitializer& ObjectInitializer){

}

UChangeSceneEvent::~UChangeSceneEvent(){

}



void  UChangeSceneEvent::Execute(){
    Super::Execute();
    auto eSceneEventEnum = GetSceneEventEnum();
    if (eSceneEventEnum == ESceneEvent::TRANS_OUT_CURRENT){
        this->SetSceneEventEnum(ESceneEvent::WAIT_TRANS_OUT_CURRENT);
        auto pCurrentScene = USceneManager::GetInstance()->GetCurrentScene();
        if (pCurrentScene){
            pCurrentScene->OnSceneDisable();
            pCurrentScene->PlayTransOutAnimation(this);
        }
        else{
            OnTransOutFinished();
        }

    }else if (eSceneEventEnum == ESceneEvent::WAIT_TRANS_OUT_CURRENT){
        auto gameController = USceneManager::GetInstance()->GetGameController();
        auto transInScene = GetTransInScene();
        checkf(transInScene, TEXT("SceneEvent eSceneEventEnum == ESceneEvent::WAIT_TRANS_OUT_CURRENT nullptr"));
    

    }else if (eSceneEventEnum == ESceneEvent::TRANS_IN_NEXT){
        this->SetSceneEventEnum(ESceneEvent::WAIT_TRANS_IN_NEXT);
        auto gameController = USceneManager::GetInstance()->GetGameController();
        auto transInScene = GetTransInScene();
        if (transInScene){
            transInScene->OnEnter(gameController);
            transInScene->PlayTransInAnimation(this);
            
        }else{
            OnTransInFinished();
        }
    }else if (eSceneEventEnum == ESceneEvent::WAIT_TRANS_IN_NEXT){
        auto gameController = USceneManager::GetInstance()->GetGameController();
        auto transInScene = GetTransInScene();
        checkf(transInScene, TEXT("SceneEvent eSceneEventEnum == ESceneEvent::WAIT_TRANS_IN_NEXT nullptr"));
    }


}

void UChangeSceneEvent::OnTransOutFinished(){
    Super::OnTransOutFinished();


}
void UChangeSceneEvent::OnTransInFinished(){
    USceneManager::GetInstance()->ClearSceneStack();
    Super::OnTransInFinished();

}


/*	if ( ULocalPlayer* Player = World->GetFirstLocalPlayerFromController() )
	{
		NewWidget->SetPlayerContext(FLocalPlayerContext(Player));
        }*/