#pragma once

#include "ModuleManager.h"

/**
 *  The public interface to this module
 */
//https://docs.unrealengine.com/latest/INT/Programming/Modules/API/index.html
//https://docs.unrealengine.com/latest/INT/Programming/Development/CodingStandard/index.html
DECLARE_LOG_CATEGORY_EXTERN(LogHorizonPlugin, Log, All);


//Most other classes are prefixed by F, though some subsystems use other letters.
//For example, FSkin is a type name, and Skin is an instance of a FSkin.
class HORIZONPLUGIN_API FHorizonPlugin : public IModuleInterface
{

public:

	/**
	 *  Singleton-like access to this module's interface. This is just for convenience!
	 *  Beware of calling this during the shutdown phase, though. Your module might have been unloaded already.
	 *
	 *  @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline FHorizonPlugin& Get()
	{
		return FModuleManager::LoadModuleChecked<FHorizonPlugin>("HorizonPlugin");
	}

	/**
	 *  Checks to see if this module is loaded and ready. It is only valid to call Get() if IsAvailable() returns true.
	 *
	 *  @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("HorizonPlugin");
	}

    /** IModuleInterface implementation */
    void StartupModule();
    void ShutdownModule();
    virtual bool IsGameModule() const
    {
        return true;
    }
   // void StartupModule();
    //void ShutdownModule();
};

