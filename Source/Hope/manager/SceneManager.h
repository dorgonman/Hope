#pragma once

class UGameScene;
class AGamePlayerController;


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
private:
    SceneManager();
    ~SceneManager();
private:
    AGamePlayerController* GameController;
    TArray<UGameScene*> SceneEventArr;
    UGameScene* CurrentScene;
};


template <typename T>
void SceneManager::ChangeScene(){
        static_assert(std::is_convertible<T*, decltype(CurrentScene) >::value,
            "T can't assign to CurrentScene");
        UGameScene* pScene = NewObject<T>();
        SceneEventArr.Add(pScene);

};