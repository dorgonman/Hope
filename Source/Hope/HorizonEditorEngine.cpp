#include "Hope.h"
#include "HorizonEditorEngine.h"
 
UHorizonEditorEngine::UHorizonEditorEngine(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{}
 
void UHorizonEditorEngine::Init(class IEngineLoop* InEngineLoop)
{
    Super::Init(InEngineLoop);
}
 
void UHorizonEditorEngine::PreExit()
{
    Super::PreExit();
}