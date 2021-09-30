#include "PushButton.h"

PushButton::PushButton(uint8_t pin, uint8_t id)
    : IController(id),
      _pin(pin),
      _prevState(false)
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
    _prevState = readState();
}

bool PushButton::readState()
{
    return PlatformFeatures::digitalGet(_pin);
}

bool PushButton::stateIsChanged()
{
    auto current = readState();
    auto stateIsChanged = _prevState != current;
    _prevState = current;

    return stateIsChanged;
}
