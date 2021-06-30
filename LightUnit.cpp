#include "LightUnit.h"
#include "Arduino.h"

LightUnit::LightUnit(Button &button, ILight &light)
{
    this->_button = &button;
    this->_light = &light;
}

LightUnit::~LightUnit()
{
}

void LightUnit::check()
{
    //Serial.println("LightUnit::check s");
    if (_button->readState())
    {
        // if ((millis() - lastDebounceTime) < debounceDelay)
        // {
        //     //Serial.println("LightUnit::check skipped");
        //     return;
        // }

        // lastDebounceTime = millis();

        Serial.println("LightUnit::check true");
        Serial.println(_light->lightsState);
        // Serial.println(__func__);
        // Serial.println(__FUNCTION__);
        // Serial.println(__PRETTY_FUNCTION__);
        _light->set(!_light->lightsState);
    }
}