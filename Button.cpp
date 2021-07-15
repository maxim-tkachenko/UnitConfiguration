#include "Button.h"
#include "AVRPlatform.h"

Button::Button(uint8_t pin)
{
    pPlatform = new AVRPlatform();

    _buttonPin = pin;
    init();
}

Button::~Button()
{
    pPlatform->print(__PRETTY_FUNCTION__);
    delete pPlatform;
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
