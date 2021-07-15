#include "ILight.h"
#include "AVRPlatform.h"

ILight::ILight(bool initialState)
{
  pPlatform = new AVRPlatform();
  log(__PRETTY_FUNCTION__);

  _ledPin = pPlatform->ledPin();

  _state = initialState;
}

ILight::~ILight()
{
  log(__PRETTY_FUNCTION__);
  delete pPlatform;
}

void ILight::init()
{
  log(__PRETTY_FUNCTION__);

  set(_state);
}

bool ILight::get()
{
  log(__PRETTY_FUNCTION__);

  return _state;
}

void ILight::set(bool state)
{
  log(__PRETTY_FUNCTION__);

  if (!_initialized)
  {
    pPlatform->pinOut(_ledPin);
    _initialized = true;
  }

  pPlatform->digitalSet(_ledPin, state);

  _state = state;
}

void ILight::switchState()
{
  log(__PRETTY_FUNCTION__);

  set(!_state);
}

void ILight::log(const char c[])
{
  pPlatform->print(c);
}
