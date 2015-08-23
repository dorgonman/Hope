#pragma once

//#include "SharedPointer.h"
#include "GameEvent.generated.h"

UCLASS()
class HOPE_API UGameEvent : public UObject{
public:
    GENERATED_BODY()
    UGameEvent(const FObjectInitializer& ObjectInitializer);
    virtual ~UGameEvent();
protected:
    UGameEvent(){};
};





