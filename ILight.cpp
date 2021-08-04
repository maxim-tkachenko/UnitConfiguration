#include "ILight.h"
#include "AVRPlatform.h"

ILight::ILight(bool initialState)
{
  pPlatform = new AVRPlatform();
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

  _ledPin = pPlatform->ledPin();
  _state = initialState;
}

ILight::~ILight()
{
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

  delete pPlatform;
}

void ILight::init()
{
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

  set(_state);
}

bool ILight::get()
{
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

  return _state;
}

void ILight::set(bool state)
{
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

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
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

  set(!_state);
}

void ILight::log(const char c[])
{
  pPlatform->print(c);
}
