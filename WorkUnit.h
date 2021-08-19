#ifndef WorkUnit_h
#define WorkUnit_h

#include "IDevice.h"
#include "IController.h"
#include "IHandler.h"
#include "Definitions.h"
#include "Diagnostics.h"

class WorkUnit
{
private:
    uint8_t _size;
    IDevice *_device;
    IController **_controllers;
    IHandler *_handler;

public:
    WorkUnit(IDevice *device, IController *controller);
    WorkUnit(IDevice *device, IController *controller, IHandler *handler);
    WorkUnit(WORKUNIT_ARGS);
    WorkUnit(WORKUNIT_ARGS, IHandler *handler);
    ~WorkUnit();
    void check();
};

#endif
