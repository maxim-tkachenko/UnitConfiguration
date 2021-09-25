#ifndef PushButtonDebounced_h
#define PushButtonDebounced_h

#include "_uint8_t.h"
#include "PushButton.h"
#include "Diagnostics.h"

class PushButtonDebounced : public PushButton
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
    PushButtonDebounced(uint8_t pin, unsigned long debounceDelayMs = 50);
    virtual ~PushButtonDebounced();
    virtual bool readState();
};

#endif
