#include "Button.h"
#include "Arduino.h"

Button::Button(uint8_t pin)
{
    _buttonPin = pin;

    init();
}

void Button::init()
{
    pinMode(_buttonPin, INPUT);
}

bool Button::readState()
{
   //Serial.println("Button::readState");
    return digitalRead(_buttonPin);
}
