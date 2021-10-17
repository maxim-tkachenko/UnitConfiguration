#include "Button.h"

Button::Button(uint8_t pin)
    : _pin(pin),
      _prevState(false)
{
    traceme;

    init();
}

Button::~Button()
{
    traceme;
}

void Button::init()
{
    traceme;

    PlatformFeatures::pinIn(_pin);
    _prevState = readState();
}

bool Button::readState()
{
    return PlatformFeatures::digitalGet(_pin);
}

StateChangedResult Button::stateIsChanged()
{
    auto current = readState();
    auto stateIsChanged = _prevState != current;
    _prevState = current;

    StateChangedResult r(stateIsChanged, current);
    return r;
}
