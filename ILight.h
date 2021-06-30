#include "Arduino.h"

#ifndef ILight_h
#define ILight_h

class ILight
{
private:
    // if debug
    static const int _ledPin = LED_BUILTIN;
    volatile bool _initialized = false;

protected:
    ILight(bool initialState);
    void log(char message[]);

public:
    bool lightsState;

    void init();
    virtual void set(bool state);
};

#endif
