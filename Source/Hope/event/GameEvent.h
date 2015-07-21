#pragma once

#include "Templates/SharedPointer.h"

class HOPE_API GameEvent {
public:
    GameEvent();
    virtual ~GameEvent();
};

class GameScene;
class HOPE_API SceneEvent {
public:

    enum class ESceneEvent{
        INIT,
        TRANS_OUT_CURRENT,
        TRANS_IN_NEXT,
        FINISHED
    };
public:
    SceneEvent();
    virtual ~SceneEvent();

    virtual void         Execute();
    void                 SetSceneEventEnum(ESceneEvent eventEnum){ SceneEventEnum = eventEnum; };
    ESceneEvent          GetSceneEventEnum(){ return SceneEventEnum; };
    bool                 IsFinished(){ return (ESceneEvent::FINISHED == SceneEventEnum); };
    TSharedPtr<GameScene>& GetInScene(){ return InScenePtr; }
    void SetInScene(GameScene* pInScene);

public:
private:

    ESceneEvent SceneEventEnum;
    TSharedPtr<GameScene> InScenePtr;
};

/*class HOPE_API ChangeSceneEvent : public SceneEvent {
public:
    ChangeSceneEvent();
    virtual ~ChangeSceneEvent();
};*/