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

    void turn(bool state);

protected:
    IDeviceBaseTurnConfiguration *_turnConfig;
    IDeviceBaseTurnConfiguration *_turnAnimation;

    IDevice(
        IDeviceBaseTurnConfiguration *config,
        IDeviceBaseTurnConfiguration *animation,
        bool initialState);
    // virtual void setImpl(bool state) = 0;
    // virtual void setDefaultTurnConfig() = 0;

public:
    virtual ~IDevice();
    void init();
    virtual bool get();
    void set(bool state, bool animate = false);
    void switchState(bool animate = false);
};

#endif
