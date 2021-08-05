#include "Light.h"

Light::Light(uint8_t relayPin, bool initialState)
    : ILight(initialState),
      _relayPin(relayPin)
{
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

  init();
}

Light::~Light()
{
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif
}

void Light::init()
{
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

  platform->pinOut(_relayPin);
  ILight::init();
}

void Light::set(bool state)
{
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

  platform->digitalSet(_relayPin, state);
  ILight::set(state);
}
