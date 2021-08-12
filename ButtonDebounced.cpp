#include "ButtonDebounced.h"

ButtonDebounced::ButtonDebounced(uint8_t pin)
    : Button(pin),
      _state(false),
      _lastState(false),
      _lastDebounceTime(0)
{
    traceme;
}

ButtonDebounced::~ButtonDebounced()
{
    traceme;
}

bool ButtonDebounced::readState()
{
    // read the state of the switch into a local variable:
    int reading = Button::readState();

    // check to see if you just pressed the button
    // (i.e. the input went from LOW to HIGH), and you've waited long enough
    // since the last press to ignore any noise:

    // If the switch changed, due to noise or pressing:
    if (reading != _lastState)
    {
        // reset the debouncing timer
        _lastDebounceTime = platform->milliseconds();
    }

    if ((platform->milliseconds() - _lastDebounceTime) > _debounceDelay)
    {
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:

        // if the button state has changed:
        if (reading != _state)
        {
            _state = reading;
            if (_state)
            {
                return true;
            }
        }
    }

    // save the reading. Next time through the loop, it'll be the _lastState:
    _lastState = reading;

    return false;
}