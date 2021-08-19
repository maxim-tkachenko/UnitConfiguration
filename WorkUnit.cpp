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

WorkUnit::WorkUnit(WORKUNIT_ARGS)
    : WorkUnit(device, controllers, size, new ControllerHandler())
{
    traceme;
}

WorkUnit::WorkUnit(WORKUNIT_ARGS, IHandler *handler)
    : _controllers(controllers),
      _size(size),
      _device(device),
      _handler(handler)
{
    traceme;
}

WorkUnit::~WorkUnit()
{
    traceme;

    for (uint8_t i = 0; i < _size; i++)
    {
        delete _controllers[i];
    }

    delete[] _controllers;
    delete _device;
    delete _handler;
}

void WorkUnit::check()
{
    _handler->Execute(_device, _controllers, _size);
}