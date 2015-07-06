#pragma once
class HOPE_API SceneManager
{
public:
    enum class EScene{
        TitleScene
    };
public:
    static SceneManager* GetInstance();
    static void Destroy();
    void Tick(float dt);

    void ChangeScene(EScene eScene);
private:
    SceneManager();
    ~SceneManager();
};

