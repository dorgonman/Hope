#pragma once

#include "ModuleManager.h"

/**
 *  The public interface to this module
 */

DECLARE_LOG_CATEGORY_EXTERN(LogHorizonEditorPlugin, Log, All);
class HORIZONEDITOR_API FHorizonEditorPlugin : public IModuleInterface
{

public:

	/**
	 *  Singleton-like access to this module's interface. This is just for convenience!
	 *  Beware of calling this during the shutdown phase, though. Your module might have been unloaded already.
	 *
	 *  @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline FHorizonEditorPlugin& Get()
	{
		return FModuleManager::LoadModuleChecked<FHorizonEditorPlugin>("HorizonEditorPlugin");
	}

	/**
	 *  Checks to see if this module is loaded and ready. It is only valid to call Get() if IsAvailable() returns true.
	 *
	 *  @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("HorizonEditorPlugin");
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

