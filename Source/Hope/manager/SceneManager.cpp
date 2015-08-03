#include "Hope.h"
#include "SceneManager.h"
#include "UMG.h"
#include "WidgetAnimation.h"
#include "scene/TitleScene.h"
#include "GamePlayerController.h"
#include "event/SceneEvent.h"

static SceneManager* s_instance = nullptr;
SceneManager::SceneManager() 
    : GameController(nullptr)
    , CurrentScene(nullptr)
{

}
SceneManager::~SceneManager(){

}
SceneManager* SceneManager::GetInstance(){
    if (nullptr == s_instance){
        s_instance = new SceneManager();
    }
    return s_instance;
}

void SceneManager::Destroy(){
    SAFE_DELETE(s_instance);
    //delete s_instance;
    //s_instance = nullptr;
}

void SceneManager::SetGameController(AGamePlayerController* pController) {
    GameController = pController;
    //pController->DisableInput(pController);
    //pController->EnableInput();
}
void SceneManager::Tick(float dt){



   /* if (m_pSceneEvenList->count() > 0)
    {
        SceneEventObject* sceneEvent = dynamic_cast<SceneEventObject*>(m_pSceneEvenList->objectAtIndex(0));
        CCAssert(sceneEvent, "");

        if (sceneEvent->isFinished())
        {
            m_pSceneEvenList->removeObject(sceneEvent);
        }
        else
        {
            sceneEvent->execute();
        }
        return;
    }

    GameScene *pCurrScene = getCurrentScene();
    if (pCurrScene)
        pCurrScene->scheduleUpdate(delta);*/


    if (SceneEventArr.Num() > 0){
        auto pEvent = SceneEventArr[0];
        if (pEvent->IsFinished()){
            CurrentScene = pEvent->GetTransInScene();
            SceneEventArr.Remove(pEvent);
            
            UE_LOG(LogHope, Log, TEXT("SceneEventArr:%d"), SceneEventArr.Num());
        }else{
            pEvent->Execute();
        
        } 
    }
 

}

