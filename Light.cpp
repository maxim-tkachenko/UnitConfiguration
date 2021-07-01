#include "Light.h"
#include "Arduino.h"

Light::Light(int relayPin, bool initialState)
    : ILight(initialState)
{
  this->relayPin = relayPin;
}

void Light::init()
{
  ILight::init();
  pinMode(relayPin, OUTPUT);
}

void Light::set(bool state)
{
  log("Light::set");

  digitalWrite(relayPin, state);
  ILight::set(state);
}
