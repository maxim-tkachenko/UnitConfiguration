#ifndef ButtonDebounced_h
#define ButtonDebounced_h

#include "Button.h"

class ButtonDebounced : public Button
{
private:
    bool buttonState;
    bool lastButtonState;

    // the following variable are unsigned longs because the time, measured in
    // milliseconds, will quickly become a bigger number than can be stored in an int.
    unsigned long lastDebounceTime;

    // the debounce time; increase if the output flickers
    unsigned long debounceDelay;

public:
    ButtonDebounced(uint8_t pin);
    virtual ~ButtonDebounced();
    virtual bool readState();
};

#endif
