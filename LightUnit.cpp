#include "LightUnit.h"
#include "Arduino.h"

LightUnit::LightUnit(Button *button, ILight *light)
{
    _button = button;
    _light = light;
}

LightUnit::~LightUnit()
{
}

void LightUnit::check()
{
    //Serial.println("LightUnit::check s");
    if (_button->readState())
    {
        Serial.println("LightUnit::check true");
        Serial.println(_light->get());
        // Serial.println(__func__);
        // Serial.println(__FUNCTION__);
        // Serial.println(__PRETTY_FUNCTION__);
        _light->switchState();
    }
}