#pragma once



#include "event/ChangeSceneEvent.h"
#include "SceneManager.generated.h"
class UGameScene;
class AGamePlayerController;
class USceneEvent;
class UChangeSceneEvent;
UCLASS()
class HOPE_API USceneManager : public UObject
{
    GENERATED_BODY()
    USceneManager(const FObjectInitializer& ObjectInitializer);
    virtual ~USceneManager();
public:
    static USceneManager* GetInstance();
    static void Destroy();

    void SetGameController(AGamePlayerController* pController); 
    void Tick(float dt);

    template <typename T>
    void ChangeScene();

    AGamePlayerController* GetGameController(){ return GameController; }

    UGameScene* GetCurrentScene(){ return CurrentScene; };
    void SetCurrentScene(UGameScene* pCurrentScene);


    template <typename T>
    void AddSceneEvent(UGameScene* pGameScene);
private:
    UPROPERTY()
    AGamePlayerController* GameController;

    UPROPERTY()
    TArray<USceneEvent*> SceneEventArr;
    UPROPERTY()
    TArray<UGameScene*> SceneStack;


    UPROPERTY()
    UGameScene* CurrentScene;
};


template <typename T>
void USceneManager::ChangeScene(){
    static_assert(std::is_convertible<T*, decltype(CurrentScene) >::value,
        "T can't assign to CurrentScene");
    UGameScene* pScene = NewObject<T>();//NewObject<T>(UGameScene::StaticClass());
    // ConstructObject<T> deprecated
    //pScene->SetFlags(GARBAGE_COLLECTION_KEEPFLAGS);
    //AWorldCell* EF6World = ConstructObject<AWorldCell>(AWorldCell::StaticClass());
    this->AddSceneEvent<UChangeSceneEvent>(pScene);
};

template <typename T>
void USceneManager::AddSceneEvent(UGameScene* pGameScene){
    static_assert(std::is_convertible<T*, USceneEvent* >::value,
        "T can't push to SceneEventArr");
    //TSharedPtr<SceneEvent> sceneEventPtr = MakeShareable(new T);
    USceneEvent* sceneEvent = NewObject<T>();
    sceneEvent->SetTransInScene(pGameScene);
    SceneEventArr.Add(sceneEvent);

};