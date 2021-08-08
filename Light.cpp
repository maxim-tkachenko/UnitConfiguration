#include "Light.h"

Light::Light(uint8_t relayPin, bool initialState)
    : ILight(initialState),
      _relayPin(relayPin)
{
  traceme;

  init();
}

Light::~Light()
{
  traceme;
}

void Light::init()
{
  traceme;

  platform->pinOut(_relayPin);
  ILight::init();
}

void Light::set(bool state)
{
  traceme;

  platform->digitalSet(_relayPin, state);
  ILight::set(state);
}
