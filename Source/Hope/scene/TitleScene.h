#pragma once

#include "GameFramework/PlayerController.h"


class HOPE_API TitleScene
{
public:
    TitleScene();
    ~TitleScene();
    void Tick(float dt);
public://scene Callback
    virtual void OnEnter();
    virtual void OnSceneVisible();
    virtual void OnExit();
    virtual void OnSceneDisable();
private:
    TSubclassOf<class UUserWidget> SceneWidgetClass;
    // Variable to hold the widget After Creating it.
    UUserWidget* SceneWidget;
};

