#include "PushButtonDebounced.h"

PushButtonDebounced::PushButtonDebounced(
    uint8_t pin,
    bool pullup,
    uint8_t id,
    unsigned long debounceDelayMs)
    : Button(pin, pullup, id),
      _state(false),
      _lastState(false),
      _debounceDelay(debounceDelayMs)
{
    traceme;
}

PushButtonDebounced::PushButtonDebounced(
    uint8_t pin,
    uint8_t id,
    unsigned long debounceDelayMs)
    : PushButtonDebounced(pin, false, id, debounceDelayMs)
{
    traceme;
}

PushButtonDebounced::~PushButtonDebounced()
{
    traceme;
}

StateChangedResult PushButtonDebounced::stateIsChanged()
{
    // read the state of the switch into a local variable:
    int reading = readState();

    // check to see if you just pressed the button
    // (i.e. the input went from LOW to HIGH), and you've waited long enough
    // since the last press to ignore any noise:

    // If the switch changed, due to noise or pressing:
    if (reading != _lastState)
    {
        // reset the debouncing timer
        _lastDebounceTime = PlatformFeatures::milliseconds();
    }

    if ((PlatformFeatures::milliseconds() - _lastDebounceTime) > _debounceDelay)
    {
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:

        // if the button state has changed:
        if (reading != _state)
        {
            _state = reading;
            if (_state)
            {
                // NOTE: _state will be always 'true' due to the nature of push button.
                return StateChangedResult(true, _state);
            }
        }
    }

    // save the reading. Next time through the loop, it'll be the _lastState:
    _lastState = reading;

    return StateChangedResult(false, reading);
}