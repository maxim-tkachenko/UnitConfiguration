#include "WorkUnit.h"

WorkUnit::WorkUnit(ILight *light, Button *button)
    : WorkUnit(
          light,
          new Button *[1]
          { button },
          1)
{
    traceme;
}

WorkUnit::WorkUnit(ILight *light, Button **button, uint8_t size)
    : _controllers(button),
      _size(size),
      _light(light)
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
    delete _light;
}

void WorkUnit::check()
{
    for (uint8_t i = 0; i < _size; i++)
    {
        if (_controllers[i]->readState())
        {
            _light->switchState();
        }
    }
}