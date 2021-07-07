#include "Arduino.h"
#include "IPlatform.h"

#ifndef ILight_h
#define ILight_h

class ILight
{
private:
    bool _state;

    // if debug
    static const int _ledPin = LED_BUILTIN;
    volatile bool _initialized = false;

protected:
    IPlatform *pPlatform;
    ILight(bool initialState);
    virtual ~ILight();
    void log(const char c[]);

public:
    void init();
    virtual bool get();
    virtual void set(bool state);
    virtual void switchState();
};

#endif
