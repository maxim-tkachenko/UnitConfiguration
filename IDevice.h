#ifndef IDevice_h
#define IDevice_h

#include "PlatformFeatures.h"
#include "_uint8_t.h"
#include "Diagnostics.h"
#include "DiagnosticsFlags.h"
#include "IDeviceTurnConfiguration.h"

class IDevice
{
private:
    bool _state;

protected:
    IDeviceBaseTurnConfiguration *_turnAnimation;

    IDevice(IDeviceBaseTurnConfiguration *animation, bool initialState = false);
    IDevice(bool initialState = false);
    virtual void setImpl(bool state) = 0;

public:
    virtual ~IDevice();
    void init();
    virtual bool get();
    void set(bool state, bool animate = false);
    void switchState(bool animate = false);
};

#endif
