#include "ILight.h"
#include "AVRPlatform.h"

ILight::ILight(bool initialState)
    : platform(new AVRPlatform()),
      _state(initialState)
{
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

  _ledPin = platform->ledPin();
}

ILight::~ILight()
{
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

  delete platform;
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
    platform->pinOut(_ledPin);
    _initialized = true;
  }

  platform->digitalSet(_ledPin, state);

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
  platform->print(c);
}
