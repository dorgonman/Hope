#pragma once



#include "scene/GameScene.h"

#include "HomeScene.generated.h"

//GameScene: manage UMG, input, game logic and interaction

UCLASS()
class HOPE_API UHomeScene : public UGameScene
{
public:
    GENERATED_BODY()
        UHomeScene(const FObjectInitializer& ObjectInitializer);
    virtual ~UHomeScene();
    void Tick(float dt);
public://scene Callback
    virtual void OnEnter(AGamePlayerController* pController);
    virtual void OnSceneVisible();
    virtual void OnExit();
    virtual void OnSceneDisable();

protected:
    virtual void OnAnimationFinished(const FString& animeName) override;
private:
    UFUNCTION()
    void StartGame();
};

