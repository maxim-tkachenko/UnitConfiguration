#ifndef WorkUnit_h
#define WorkUnit_h

#include "IDevice.h"
#include "IController.h"
#include "ControllerHandler.h"
#include "Diagnostics.h"

class WorkUnit
{
private:
    uint8_t _size;
    IDevice *_device;
    IController **_controllers;
    ControllerHandler *_handler;

public:
    WorkUnit(IDevice *device, IController *controller);
    WorkUnit(IDevice *device, IController *controller, ControllerHandler *handler);
    WorkUnit(IDevice *device, IController **controllers, uint8_t size);
    WorkUnit(IDevice *device, IController **controllers, uint8_t size, ControllerHandler *handler);
    ~WorkUnit();
    void check();
};

#endif
