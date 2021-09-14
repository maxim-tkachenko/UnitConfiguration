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

    template <class TDevice, class TDefaultTurnConfig>
    void initConfigs(
        IDeviceTurnConfiguration<TDevice> *config,
        IDeviceTurnConfiguration<TDevice> *animation,
        TDevice *instance)
    {
        if (config == nullptr)
        {
            config = new TDefaultTurnConfig();
            _turnConfig = config;
        }

        initConfigs<TDevice>(config, animation, instance);
    }

    template <class TDevice>
    void initConfigs(
        IDeviceTurnConfiguration<TDevice> *config,
        IDeviceTurnConfiguration<TDevice> *animation,
        TDevice *instance)
    {
        if (config != nullptr)
        {
            config->init(instance);
        }

        if (animation != nullptr)
        {
            animation->init(instance);
        }
    }

public:
    virtual ~IDevice();
    void init();
    virtual bool get();
    void set(bool state, bool animate = false);
    void switchState(bool animate = false);
};

#endif
