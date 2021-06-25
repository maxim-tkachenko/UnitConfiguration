#include "Arduino.h"

#ifndef ILight_h
#define ILight_h

class ILight
{
private:
    // if debug
    static const int _ledPin = LED_BUILTIN;
    volatile bool _initialized = false;

    int _buttonPin;

public:
    bool lightsState;
    bool buttonState;
    bool lastButtonState;

    // the following variable are unsigned longs because the time, measured in
    // milliseconds, will quickly become a bigger number than can be stored in an int.
    unsigned long lastDebounceTime = 0;

    void init();
    virtual void set(bool state);
    uint8_t readButtonState();
    void log(char message[]);

protected:
    ILight(
        int buttonPin,
        bool initialState);
};

#endif
