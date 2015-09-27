#include "Engine.h"
#include "HorizonPlugin.h"
DEFINE_LOG_CATEGORY(LogHorizonPlugin);

void FHorizonPlugin::StartupModule()
{
    UE_LOG(LogHorizonPlugin, Log, TEXT("StartupModule"));
}

void FHorizonPlugin::ShutdownModule()
{
    UE_LOG(LogHorizonPlugin, Log, TEXT("ShutdownModule"));
}


IMPLEMENT_MODULE(FHorizonPlugin, HorizonPlugin)