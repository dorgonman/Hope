#include "Hope.h"
#include "SceneManager.h"
#include "UMG.h"
#include "WidgetAnimation.h"
#include "scene/TitleScene.h"
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
}
void SceneManager::Tick(float dt){
    if (SceneEventArr.Num() > 0){
        UTitleScene* pScene = SceneEventArr.Pop();
        pScene->OnEnter(GameController);
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


void SceneManager::ChangeScene(EScene eScene){
    UTitleScene* pTitleScene = NewObject<UTitleScene>();
    SceneEventArr.Add(pTitleScene);
}