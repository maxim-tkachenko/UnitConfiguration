#include "ILight.h"
#include "Arduino.h"
#include "AVRPlatform.h"

ILight::ILight(bool initialState)
{
  pPlatform = new AVRPlatform();
  this->_state = initialState;
}

ILight::~ILight()
{
  delete pPlatform;
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

void ILight::log(const char c[])
{
  pPlatform->print(c);
}
