#include "Engine.h"
#include "MyDeveloperPlugin.h"
DEFINE_LOG_CATEGORY(LogHorizonDeveloperPlugin);

void FHorizonDeveloperPlugin::StartupModule()
{
    UE_LOG(LogHorizonDeveloperPlugin, Log, TEXT("StartupModule"));
}

void FHorizonDeveloperPlugin::ShutdownModule()
{
    UE_LOG(LogHorizonDeveloperPlugin, Log, TEXT("ShutdownModule"));
}


IMPLEMENT_MODULE(FHorizonDeveloperPlugin, HorizonDeveloperPlugin)