#include "Light.h"

Light::Light(int relayPin, bool initialState)
    : ILight(initialState)
{
  this->relayPin = relayPin;
  init();
}

Light::~Light()
{
  pPlatform->print(__PRETTY_FUNCTION__);
}

void Light::init()
{
  ILight::init();
  pPlatform->pinOut(relayPin);
}

void Light::set(bool state)
{
  log("Light::set");

  pPlatform->digitalSet(relayPin, state);
  ILight::set(state);
}
