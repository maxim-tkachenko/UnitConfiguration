#ifndef SwitchButton_h
#define SwitchButton_h

#include "_uint8_t.h"
#include "Button.h"
#include "Diagnostics.h"

class SwitchButton : public Button
{
private:
    bool _state;
    bool _lastState;

    // the following variable are unsigned longs because the time, measured in
    // milliseconds, will quickly become a bigger number than can be stored in an int.
    unsigned long _lastDebounceTime = 0;

    // the debounce time; increase if the output flickers
    unsigned long _debounceDelay;

public:
    SwitchButton(uint8_t pin, uint8_t id = 0, unsigned long debounceDelayMs = 50);
    virtual ~SwitchButton();
    virtual bool stateIsChanged() override;
};

#endif
