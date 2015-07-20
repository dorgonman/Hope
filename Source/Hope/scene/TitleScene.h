#pragma once



#include "scene/GameScene.h"

#include "TitleScene.generated.h"

//GameScene: manage UMG, input, game logic and interaction

UCLASS()
class HOPE_API UTitleScene : public UGameScene
{
public:
    GENERATED_BODY()
    UTitleScene(const FObjectInitializer& ObjectInitializer);
    void Tick(float dt);
public://scene Callback
    virtual void OnEnter(AGamePlayerController* pController);
    virtual void OnSceneVisible();
    virtual void OnExit();
    virtual void OnSceneDisable();

};

