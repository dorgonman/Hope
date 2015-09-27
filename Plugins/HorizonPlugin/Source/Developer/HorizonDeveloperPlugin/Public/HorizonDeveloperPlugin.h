#pragma once

#include "ModuleManager.h"

/**
 *  The public interface to this module
 */

DECLARE_LOG_CATEGORY_EXTERN(LogHorizonDeveloperPlugin, Log, All);
class HORIZONDEVELOPER_API FHorizonDeveloperPlugin : public IModuleInterface
{

public:

	/**
	 *  Singleton-like access to this module's interface. This is just for convenience!
	 *  Beware of calling this during the shutdown phase, though. Your module might have been unloaded already.
	 *
	 *  @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline FHorizonDeveloperPlugin& Get()
	{
		return FModuleManager::LoadModuleChecked<FHorizonDeveloperPlugin>("HorizonDeveloperPlugin");
	}

	/**
	 *  Checks to see if this module is loaded and ready. It is only valid to call Get() if IsAvailable() returns true.
	 *
	 *  @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("HorizonDeveloperPlugin");
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

