#include "WorkUnit.h"
#include "ControllerHandler.h"

WorkUnit::WorkUnit(IDevice *device, IController *controller)
    : WorkUnit(device, controller, new ControllerHandler())
{
    traceme;
}

WorkUnit::WorkUnit(IDevice *device, IController *controller, IHandler *handler)
    : WorkUnit(
          device,
          new IController *[1]
          { controller },
          1,
          handler)
{
    traceme;
}

WorkUnit::WorkUnit(IDevice *device, IController **controllers, uint8_t controllersCount)
    : WorkUnit(
          new IDevice *[1]
          { device },
          1,
          controllers,
          controllersCount,
          new ControllerHandler())
{
    traceme;
}

WorkUnit::WorkUnit(IDevice *device, IController **controllers, uint8_t controllersCount, IHandler *handler)
    : WorkUnit(
          new IDevice *[1]
          { device },
          1,
          controllers,
          controllersCount,
          handler)
{
    traceme;
}

WorkUnit::WorkUnit(WORKUNIT_ARGS)
    : WorkUnit(devices, devicesCount, controllers, controllersCount, new ControllerHandler())
{
    traceme;
}

WorkUnit::WorkUnit(WORKUNIT_ARGS, IHandler *handler)
    : _devices(devices),
      _devicesCount(devicesCount),
      _controllers(controllers),
      _controllersCount(controllersCount),
      _handler(handler)
{
    traceme;
}

// TODO: this could throw an exception when freeing already freed pointer.
WorkUnit::~WorkUnit()
{
    traceme;

    for (uint8_t ci = 0; ci < _controllersCount; ci++)
    {
        delete _controllers[ci];
    }

    delete[] _controllers;

    for (uint8_t di = 0; di < _devicesCount; di++)
    {
        delete _devices[di];
    }

    delete[] _devices;
    delete _handler;
}

void WorkUnit::check()
{
    _handler->Execute(_devices, _devicesCount, _controllers, _controllersCount);
}