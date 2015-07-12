#pragma once

class UTitleScene;
class AGamePlayerController;
class HOPE_API SceneManager
{
public:
    enum class EScene{
        TitleScene
    };
public:
    static SceneManager* GetInstance();
    static void Destroy();

    void SetGameController(AGamePlayerController* pController); 
    void Tick(float dt);

    void ChangeScene(EScene eScene);
private:
    SceneManager();
    ~SceneManager();
private:
    AGamePlayerController* GameController;
    TArray<UTitleScene*> SceneEventArr;
};

