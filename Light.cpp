#include "Light.h"

Light::Light(uint8_t relayPin, bool initialState)
    : IDevice(initialState),
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
  IDevice::init();
}

void Light::set(bool state)
{
  traceme;

  platform->digitalSet(_relayPin, state);
  IDevice::set(state);
}
