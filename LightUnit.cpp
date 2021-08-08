#include "LightUnit.h"

LightUnit::LightUnit(Button *button, ILight *light)
    : _button(button),
      _light(light)
{
    traceme;
}

LightUnit::~LightUnit()
{
    traceme;

    delete _button;
    delete _light;
}

void LightUnit::check()
{
    if (_button->readState())
    {
        _light->switchState();
    }
}