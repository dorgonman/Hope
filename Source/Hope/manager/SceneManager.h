#pragma once


#include "event/SceneEvent.h"
class UGameScene;
class AGamePlayerController;
class SceneEvent;

class HOPE_API SceneManager
{

public:
    static SceneManager* GetInstance();
    static void Destroy();

    void SetGameController(AGamePlayerController* pController); 
    void Tick(float dt);

    template <typename T>
    void ChangeScene();

    AGamePlayerController* GetGameController(){ return GameController; }

    UGameScene* GetCurrentScene(){ return CurrentScene; };
    void SetCurrentScene(UGameScene* pCurrentScene);
private:
    SceneManager();
    ~SceneManager();


    template <typename T>
    void AddSceneEvent(UGameScene* pGameScene);
private:
    AGamePlayerController* GameController;



    TArray<TSharedPtr<SceneEvent>> SceneEventArr;
    TArray<UGameScene*> SceneStack;


    UPROPERTY()
    UGameScene* CurrentScene;
};


template <typename T>
void SceneManager::ChangeScene(){
    static_assert(std::is_convertible<T*, decltype(CurrentScene) >::value,
        "T can't assign to CurrentScene");
    UGameScene* pScene = NewObject<T>();//NewObject<T>(UGameScene::StaticClass());
    // ConstructObject<T> deprecated
    pScene->SetFlags(GARBAGE_COLLECTION_KEEPFLAGS);
    //AWorldCell* EF6World = ConstructObject<AWorldCell>(AWorldCell::StaticClass());
    this->AddSceneEvent<ChangeSceneEvent>(pScene);
};

template <typename T>
void SceneManager::AddSceneEvent(UGameScene* pGameScene){
    static_assert(std::is_convertible<T*, SceneEvent* >::value,
        "T can't push to SceneEventArr");
    TSharedPtr<SceneEvent> sceneEventPtr = MakeShareable(new T);
    sceneEventPtr->SetTransInScene(pGameScene);
    SceneEventArr.Add(sceneEventPtr);

};