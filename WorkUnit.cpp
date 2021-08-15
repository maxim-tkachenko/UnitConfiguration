#include "WorkUnit.h"

WorkUnit::WorkUnit(Button *button, ILight *light)
    : _button(button),
      _light(light)
{
    traceme;
}

WorkUnit::~WorkUnit()
{
    traceme;

    delete _button;
    delete _light;
}

void WorkUnit::check()
{
    if (_button->readState())
    {
        _light->switchState();
    }
}