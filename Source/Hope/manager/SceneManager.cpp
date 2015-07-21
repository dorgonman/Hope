#include "Hope.h"
#include "SceneManager.h"
#include "UMG.h"
#include "WidgetAnimation.h"
#include "scene/TitleScene.h"
#include "GamePlayerController.h"
SceneManager::SceneManager() : GameController(nullptr){

}
SceneManager::~SceneManager(){

}
SceneManager* SceneManager::GetInstance(){
    static SceneManager s_instance;
    return &s_instance;
}

void SceneManager::Destroy(){

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

     

        if (nullptr != this->CurrentScene){
            CurrentScene->ConditionalBeginDestroy(); //essential extra step, in all my testing
            CurrentScene = nullptr;
        }
        this->CurrentScene = SceneEventArr.Pop();
        CurrentScene->OnEnter(GameController);
        //pScene->BeginDestroy();
    }
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
    }*/

}

