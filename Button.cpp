#include "Button.h"

Button::Button(uint8_t pin, bool pullup, uint8_t id)
    : IController(id),
      _pin(pin),
      _pullup(pullup),
      _prevState(false)
{
    traceme;

    init();
}

Button::Button(uint8_t pin, uint8_t id)
    : Button(pin, false, id)
{
    traceme;
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
