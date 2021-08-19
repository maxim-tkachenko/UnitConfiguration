#ifndef ControllerHandler_h
#define ControllerHandler_h

#include "IProcessor.h"

class ControllerHandler : public IProcessor
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
