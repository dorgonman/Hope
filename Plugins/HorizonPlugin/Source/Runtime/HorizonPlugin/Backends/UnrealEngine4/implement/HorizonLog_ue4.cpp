#include "Engine.h"
#include "HorizonPlugin.h"
#undef check
#include "HorizonLog.h"


namespace horizon{


    void HorizonLogBasicBackend::logMessageImplement(const std::string& msg){
        FPlatformMisc::LowLevelOutputDebugString(TEXT("HorizonLogBasicBackend test"));
    }

    void HorizonLogBasicFormatedBackend::logMessageImplement(const std::string& msg){
        FPlatformMisc::LowLevelOutputDebugString(UTF8_TO_TCHAR(msg.c_str()));
        //FPlatformMisc::LowLevelOutputDebugString(TEXT(msg.c_str()));
    }
     

}//namespace horizon