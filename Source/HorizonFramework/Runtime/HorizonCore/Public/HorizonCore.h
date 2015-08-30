#ifndef __HORIZON_CORE_H__
#define __HORIZON_CORE_H__

#include "ModuleInterface.h"


/** Module interface for this game's loading screens */
class IHorizonCoreModule : public IModuleInterface
{
public:
  
    virtual void DumpModuleInfo() = 0;
};

#endif // __HORIZON_CORE_H__
