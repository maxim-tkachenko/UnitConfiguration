#include "LightUnit.h"

LightUnit::LightUnit(Button *button, ILight *light)
{
    _button = button;
    _light = light;
}

LightUnit::~LightUnit()
{
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