#ifndef ButtonDebounced_h
#define ButtonDebounced_h

#include "_uint8_t.h"
#include "Button.h"

class ButtonDebounced : public Button
{
private:
    bool _buttonState;
    bool _lastButtonState;

    // the following variable are unsigned longs because the time, measured in
    // milliseconds, will quickly become a bigger number than can be stored in an int.
    unsigned long _lastDebounceTime;

    // the debounce time; increase if the output flickers
    unsigned long _debounceDelay;

public:
    ButtonDebounced(uint8_t pin);
    virtual ~ButtonDebounced();
    virtual bool readState();
};

#endif
