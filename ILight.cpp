#include "ILight.h"
#include "Arduino.h"

ILight::ILight(
    int buttonPin,
    bool initialState)
{
  this->_buttonPin = buttonPin;
  this->lightsState = initialState;
}

void ILight::init()
{
  log("ILight::init s");

  pinMode(_buttonPin, INPUT);
  set(lightsState);

  log("ILight::init e");
}

void ILight::set(bool state)
{
  log("ILight::set s");

  if (!_initialized)
  {
    pinMode(_ledPin, OUTPUT);
    _initialized = true;
  }

  digitalWrite(_ledPin, state);

  lightsState = state;

  log("ILight::set e");
}

uint8_t ILight::readButtonState()
{
  return digitalRead(_buttonPin);
}

void ILight::log(char message[])
{
  Serial.println(message);
  //delay(100);
}
