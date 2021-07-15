#include "LightUnit.h"

LightUnit::LightUnit(Button *button, ILight *light)
{
    platform.print(__PRETTY_FUNCTION__);

    _button = button;
    _light = light;
}

LightUnit::~LightUnit()
{
    platform.print(__PRETTY_FUNCTION__);

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