#include "Button.h"
#include "AVRPlatform.h"

Button::Button(uint8_t pin)
{
    _buttonPin = pin;
    pPlatform = new AVRPlatform();

    init();
}

void Button::init()
{
    pPlatform->pinIn(_buttonPin);
}

bool Button::readState()
{
    //Serial.println("Button::readState");
    return pPlatform->digitalGet(_buttonPin);
}
