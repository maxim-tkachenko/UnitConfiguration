#include "ILight.h"
#include "AVRPlatform.h"

ILight::ILight(bool initialState)
    : platform(new AVRPlatform()),
      _state(initialState)
{
  traceme;

  _ledPin = platform->ledPin();
}

ILight::~ILight()
{
  traceme;

  delete platform;
}

void ILight::init()
{
  traceme;

  set(_state);
}

bool ILight::get()
{
  traceme;

  return _state;
}

void ILight::set(bool state)
{
  traceme;

  if (!_initialized)
  {
    platform->pinOut(_ledPin);
    _initialized = true;
  }

  platform->digitalSet(_ledPin, state);

  _state = state;
}

void ILight::switchState()
{
  traceme;

  set(!_state);
}
