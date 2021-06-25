#include "ILight.h"
#include "Arduino.h"

ILight::ILight(
  int buttonPin,
  bool initialState) {
  this->buttonPin = buttonPin;
  this->lightsState = initialState;
}

void ILight::init() {
  log("ILight::init s");

  pinMode(buttonPin, INPUT);
  set(lightsState);  // verify what's called

  log("ILight::init e");
}

void ILight::set(bool state) {
  log("ILight::set s");

  if (!_initialized) {
    pinMode(ledPin, OUTPUT);
    _initialized = true;
  }

  digitalWrite(ledPin, state);

  lightsState = state;

  log("ILight::set e");
}

void ILight::log(char message[]) {
  Serial.println(message);
  //delay(100);
}
