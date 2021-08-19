#ifndef ControllerHandler_h
#define ControllerHandler_h

#include "IHandler.h"

class ControllerHandler : public IHandler
{
public:
    // ControllerHandler();
    // virtual ~ControllerHandler();
    virtual bool Execute(
        IDevice *device,
        IController **controllers,
        uint8_t size);
};

#endif
