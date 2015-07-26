#pragma once



class HOPE_API GameEvent {
public:
    GameEvent();
    virtual ~GameEvent();
};

class UGameScene;
class HOPE_API SceneEvent : public GameEvent{
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



    UGameScene* GetTransInScene();
    void SetTransInScene(UGameScene* pTransInScene);

public:
private:

    ESceneEvent SceneEventEnum;
    UGameScene* TransInScene;
};

class HOPE_API ChangeSceneEvent : public SceneEvent {
public:
    ChangeSceneEvent();
    virtual ~ChangeSceneEvent();
    virtual void         Execute() override;
};