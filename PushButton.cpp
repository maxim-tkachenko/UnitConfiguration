#include "PushButton.h"
#include "AVRPlatform.h"

PushButton::PushButton(uint8_t pin)
    : platform(new AVRPlatform()),
      _pin(pin)
{
    traceme;

    init();
}

PushButton::~PushButton()
{
    traceme;

    delete platform;
}

void PushButton::init()
{
    traceme;

    platform->pinIn(_pin);
}

bool PushButton::readState()
{
    return platform->digitalGet(_pin);
}
