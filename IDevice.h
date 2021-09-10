#ifndef IDevice_h
#define IDevice_h

#include "PlatformFeatures.h"
#include "_uint8_t.h"
#include "Diagnostics.h"
#include "DiagnosticsFlags.h"
#include "IAnimation.h"

class IDevice
{
private:
    IBaseAnimation *_turnAnimation;
    bool _state;

protected:
    IDevice(IBaseAnimation *animation, bool initialState = false);
    IDevice(bool initialState = false);
    virtual void setImpl(bool state) = 0;

public:
    virtual ~IDevice();
    void init();
    virtual bool get();
    void set(bool state, bool animate = false);
    void switchState(bool animate = false);
    void setAnimation(IBaseAnimation *animation)
    {
        _turnAnimation = animation;
    }
};

#endif
