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
    IDevice **_devices;
    uint8_t _devicesCount;

    IController **_controllers;
    uint8_t _controllersCount;

    IHandler **_handlers;
    uint8_t _handlersCount;

public:
    WorkUnit(IDevice *device, IController *controller);
    WorkUnit(IDevice *device, IController *controller, IHandler *handler);
    WorkUnit(IDevice *device, IController *controller, IHandler **handlers, uint8_t handlersCount);
    WorkUnit(IDevice *device, IController **controllers, uint8_t controllersCount);
    WorkUnit(IDevice *device, IController **controllers, uint8_t controllersCount, IHandler *handler);
    WorkUnit(IDevice *device, IController **controllers, uint8_t controllersCount, IHandler **handlers, uint8_t handlersCount);
    WorkUnit(WORKUNIT_ARGS);
    WorkUnit(WORKUNIT_ARGS, IHandler *handler);
    WorkUnit(WORKUNIT_ARGS, IHandler **handlers, uint8_t handlersCount);
    ~WorkUnit();
    void check();
};

#endif
