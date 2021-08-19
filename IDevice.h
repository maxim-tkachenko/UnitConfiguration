#ifndef IDevice_h
#define IDevice_h

#include "IPlatform.h"
#include "_uint8_t.h"
#include "Diagnostics.h"

class IDevice
{
private:
    bool _state;

    // if debug
    uint8_t _ledPin = 255;

protected:
    IPlatform *platform;
    static bool _initialized;
    IDevice(bool initialState = false);

public:
    virtual ~IDevice();
    void init();
    virtual bool get();
    virtual void set(bool state);
    virtual void switchState();
};

#endif
