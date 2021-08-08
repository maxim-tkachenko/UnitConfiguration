#include "Button.h"
#include "AVRPlatform.h"

Button::Button(uint8_t pin)
    : platform(new AVRPlatform()),
      _pin(pin)
{
    traceme;

    init();
}

Button::~Button()
{
    traceme;

    delete platform;
}

void Button::init()
{
    traceme;

    platform->pinIn(_pin);
}

bool Button::readState()
{
    return platform->digitalGet(_pin);
}
