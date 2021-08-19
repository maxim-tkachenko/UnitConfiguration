#ifndef ControllerHandler_h
#define ControllerHandler_h

#include "IHandler.h"
#include "Definitions.h"

class ControllerHandler : public IHandler
{
public:
    // ControllerHandler();
    // virtual ~ControllerHandler();
    virtual bool Execute(WORKUNIT_ARGS);
};

#endif
