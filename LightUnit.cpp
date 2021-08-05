#include "LightUnit.h"

LightUnit::LightUnit(Button *button, ILight *light)
    : _button(button),
      _light(light)
{
#ifdef CALL_TRACING_ENABLED
    platform.print(__PRETTY_FUNCTION__);
#endif
}

LightUnit::~LightUnit()
{
#ifdef CALL_TRACING_ENABLED
    platform.print(__PRETTY_FUNCTION__);
#endif

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