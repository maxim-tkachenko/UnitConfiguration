#ifndef WorkUnit_h
#define WorkUnit_h

#include "IDevice.h"
#include "IController.h"
#include "IProcessor.h"
#include "Diagnostics.h"

class WorkUnit
{
private:
    uint8_t _size;
    IDevice *_device;
    IController **_controllers;
    IProcessor *_processor;

public:
    WorkUnit(IDevice *device, IController *controller);
    WorkUnit(IDevice *device, IController *controller, IProcessor *processor);
    WorkUnit(IDevice *device, IController **controllers, uint8_t size);
    WorkUnit(IDevice *device, IController **controllers, uint8_t size, IProcessor *processor);
    ~WorkUnit();
    void check();
};

#endif
