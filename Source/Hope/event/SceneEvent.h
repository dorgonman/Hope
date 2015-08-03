#pragma once

#include "SharedPointer.h"
class HOPE_API GameEvent : public TSharedFromThis< GameEvent >{
public:
    GameEvent();
    virtual ~GameEvent();
};







class UGameScene;
class HOPE_API SceneEvent : public GameEvent {
public:

    enum class ESceneEvent{
        INIT,
        TRANS_OUT_CURRENT,
        WAIT_TRANS_OUT_CURRENT,
        TRANS_IN_NEXT,
        WAIT_TRANS_IN_NEXT,
        FINISHED
    };
public:
    SceneEvent();
    virtual ~SceneEvent();

    virtual void         Execute();
    void                 SetSceneEventEnum(ESceneEvent eventEnum){ SceneEventEnum = eventEnum; };
    ESceneEvent          GetSceneEventEnum(){ return SceneEventEnum; };
    bool                 IsFinished(){ return (ESceneEvent::FINISHED == SceneEventEnum); };



    UGameScene* GetTransInScene();
    void SetTransInScene(UGameScene* pTransInScene);

public: //ISceneEventListener
    virtual void OnTransOutFinished();
    virtual void OnTransInFinished();
private:

    ESceneEvent SceneEventEnum;
    UPROPERTY()
    UGameScene* TransInScene;
};

class HOPE_API ChangeSceneEvent : public SceneEvent {
public:
    ChangeSceneEvent();
    virtual ~ChangeSceneEvent();
    virtual void         Execute() override;
};