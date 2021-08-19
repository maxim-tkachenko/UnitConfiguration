#ifndef IDevice_h
#define IDevice_h

#include "PlatformFeatures.h"
#include "_uint8_t.h"
#include "Diagnostics.h"
#include "DiagnosticsFlags.h"

class IDevice
{
private:
    bool _state;

protected:
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
