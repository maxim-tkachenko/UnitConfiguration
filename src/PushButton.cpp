#include "PushButton.h"

PushButton::PushButton(uint8_t pin)
    : IController(),
      _pin(pin)
{
    traceme;

    init();
}

PushButton::~PushButton()
{
    traceme;
}

void PushButton::init()
{
    traceme;

    PlatformFeatures::pinIn(_pin);
}

bool PushButton::readState()
{
    return PlatformFeatures::digitalGet(_pin);
}
