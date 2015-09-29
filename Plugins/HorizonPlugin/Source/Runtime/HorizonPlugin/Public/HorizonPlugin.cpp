#include "Engine.h"

#include "HorizonPlugin.h"
#include "Misc/OutputDevice.h"
#undef check
#include "HorizonLog.h"
#include "HorizonCore.h"
//#include "AllowWindowsPlatformTypes.h"
//#include "HideWindowsPlatformTypes.h"
DEFINE_LOG_CATEGORY(LogHorizonPlugin);

void FHorizonPlugin::StartupModule()
{
    // FPaths::ConvertRelativePathToFull(FPaths::GameSavedDir());
    // FPaths::ConvertRelativePathToFull(FPaths::GameIntermediateDir());
   // UE_LOG(LogHorizonPlugin, Log, TEXT("StartupModule"));
    //UE_LOG(LogTemp, Warning, TEXT("Your message"));
    horizon::HorizonCore::GetInstance()->init();
    std::string logFilePath = "HorizonLog.txt";
    horizon::HorizonCore::GetInstance()->initDefaultLog(logFilePath);
    HORIZON_INFO << "TEST" << "\n" << "test2";

    HORIZON_DEBUG << "DEBUG MESSAGE" << "\n" << "test2";
   // check(false);
   // GROWABLE_LOGF(
        //FPlatformMisc::LowLevelOutputDebugString(TEXT("====================test============================="));
    //);
}

void FHorizonPlugin::ShutdownModule()
{
    UE_LOG(LogTemp, Log, TEXT("ShutdownModule"));
}


IMPLEMENT_MODULE(FHorizonPlugin, HorizonPlugin)