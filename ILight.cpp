#include "ILight.h"
#include "Arduino.h"

ILight::ILight(bool initialState)
{
  this->lightsState = initialState;
}

void ILight::init()
{
  log("ILight::init s");

  set(lightsState);

  log("ILight::init e");
}

void ILight::set(bool state)
{
  log("ILight::set s");

  if (!_initialized)
  {
    pinMode(_ledPin, OUTPUT);
    _initialized = true;
  }

  digitalWrite(_ledPin, state);

  lightsState = state;

  log("ILight::set e");
}

void ILight::log(char message[])
{
  //Serial.println(__PRETTY_FUNCTION__);
  //Serial.println(message);
  //delay(100);
}
