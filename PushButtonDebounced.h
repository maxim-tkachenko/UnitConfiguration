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
    unsigned long _lastDebounceTime;

    // the debounce time; increase if the output flickers
    inline static unsigned long _debounceDelay = 50;

public:
    PushButtonDebounced(uint8_t pin);
    virtual ~PushButtonDebounced();
    virtual bool readState();
};

#endif
