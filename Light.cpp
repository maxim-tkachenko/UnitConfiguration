#include "Light.h"

Light::Light(uint8_t dataPin, bool initialState)
    : IDevice(initialState),
      _dataPin(dataPin)
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

  platform->pinOut(_dataPin);
  IDevice::init();
}

void Light::set(bool state)
{
  traceme;

  platform->digitalSet(_dataPin, state);
  IDevice::set(state);
}
