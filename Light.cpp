#include "Light.h"

Light::Light(int relayPin, bool initialState)
    : ILight(initialState)
{
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

  this->relayPin = relayPin;
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

  pPlatform->pinOut(relayPin);
  ILight::init();
}

void Light::set(bool state)
{
#ifdef CALL_TRACING_ENABLED
  log(__PRETTY_FUNCTION__);
#endif

  pPlatform->digitalSet(relayPin, state);
  ILight::set(state);
}
