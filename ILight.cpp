#include "ILight.h"
#include "Arduino.h"

ILight::ILight(bool initialState)
{
  this->_state = initialState;
}

void ILight::init()
{
  log("ILight::init s");

  set(_state);

  log("ILight::init e");
}

bool ILight::get()
{
  return _state;
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

  _state = state;

  log("ILight::set e");
}

void ILight::switchState()
{
  set(!_state);
}

void ILight::log(char message[])
{
  //Serial.println(__PRETTY_FUNCTION__);
  //Serial.println(message);
  //delay(100);
}
