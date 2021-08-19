#ifndef ControllerHandler_h
#define ControllerHandler_h

#include "IDevice.h"
#include "IController.h"

class ControllerHandler
{
public:
    // ControllerHandler();
    // virtual ~ControllerHandler();
    virtual bool Execute(IDevice *device, IController **controllers, uint8_t size);
};

#endif
