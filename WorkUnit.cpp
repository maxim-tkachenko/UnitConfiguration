#include "WorkUnit.h"

WorkUnit::WorkUnit(IDevice *device, Button *button)
    : WorkUnit(
          device,
          new Button *[1]
          { button },
          1)
{
    traceme;
}

WorkUnit::WorkUnit(IDevice *device, Button **button, uint8_t size)
    : _controllers(button),
      _size(size),
      _device(device)
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
}

void WorkUnit::check()
{
    for (uint8_t i = 0; i < _size; i++)
    {
        if (_controllers[i]->readState())
        {
            _device->switchState();
        }
    }
}