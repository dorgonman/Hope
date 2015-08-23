#pragma once

//#include "SharedPointer.h"
#include "GameEvent.h"
#include "SceneEvent.generated.h"





class UGameScene;
UCLASS()
class HOPE_API USceneEvent : public UGameEvent {
public:
    GENERATED_BODY()
    USceneEvent(const FObjectInitializer& ObjectInitializer);
    virtual ~USceneEvent();
protected:
    USceneEvent(){};
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
    UPROPERTY(Category = SceneEvent, EditAnywhere, AdvancedDisplay)
    UGameScene* TransInScene;
};
