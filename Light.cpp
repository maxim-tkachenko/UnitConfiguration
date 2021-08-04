#include "Light.h"

Light::Light(int relayPin, bool initialState)
    : ILight(initialState)
{
  log(__PRETTY_FUNCTION__);

  this->relayPin = relayPin;
  init();
}

Light::~Light()
{
  pPlatform->print(__PRETTY_FUNCTION__);
}

void Light::init()
{
  log(__PRETTY_FUNCTION__);

  pPlatform->pinOut(relayPin);
  ILight::init();
}

void Light::set(bool state)
{
  log(__PRETTY_FUNCTION__);

  pPlatform->digitalSet(relayPin, state);
  ILight::set(state);
}
