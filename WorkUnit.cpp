#include "WorkUnit.h"
#include "ControllerHandler.h"

WorkUnit::WorkUnit(IDevice *device, IController *controller)
    : WorkUnit(device, controller, new ControllerHandler())
{
    traceme;
}

WorkUnit::WorkUnit(IDevice *device, IController *controller, IProcessor *processor)
    : WorkUnit(
          device,
          new IController *[1]
          { controller },
          1,
          processor)
{
    traceme;
}

WorkUnit::WorkUnit(IDevice *device, IController **controllers, uint8_t size)
    : WorkUnit(device, controllers, size, new ControllerHandler())
{
    traceme;
}

WorkUnit::WorkUnit(IDevice *device, IController **controllers, uint8_t size, IProcessor *processor)
    : _controllers(controllers),
      _size(size),
      _device(device),
      _processor(processor)
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
    delete _processor;
}

void WorkUnit::check()
{
    _processor->Execute(_device, _controllers, _size);
}