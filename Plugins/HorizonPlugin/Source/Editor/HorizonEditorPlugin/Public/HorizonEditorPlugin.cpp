#include "Engine.h"
#include "MyEditorPlugin.h"
DEFINE_LOG_CATEGORY(LogHorizonEditorPlugin);

void FMyEditorPlugin::StartupModule()
{
    UE_LOG(LogHorizonEditorPlugin, Log, TEXT("StartupModule"));
}

void FMyEditorPlugin::ShutdownModule()
{
    UE_LOG(LogHorizonEditorPlugin, Log, TEXT("ShutdownModule"));
}


IMPLEMENT_MODULE(FMyEditorPlugin, MyEditorPlugin)