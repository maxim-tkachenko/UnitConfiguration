#include "Button.h"

Button::Button(uint8_t pin, uint8_t id, bool pullup)
    : IController(id),
      _pin(pin),
      _pullup(pullup),
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

    PlatformFeatures::pinIn(_pin, _pullup);
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

    return StateChangedResult(stateIsChanged, current);
}
