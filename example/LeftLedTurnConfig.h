#ifndef LeftLedTurnConfig_h
#define LeftLedTurnConfig_h

#include <UnitConfiguration.h>

class LeftLedTurnConfig : public IDeviceTurnConfiguration<FastLedLight>
{
private:
    void set(CRGB color)
    {
        fill_solid(_device->ledController->leds(), _device->ledController->size(), color);
        _device->ledController->showLeds(1);
    }

public:
    LeftLedTurnConfig()
    {
        traceme;
    }

    bool on(uint8_t requestorId) override
    {
        traceme;

        (void)requestorId;

        set(CRGB::Green);
        return true;
    }

    bool off(uint8_t requestorId) override
    {
        traceme;

        (void)requestorId;

        set(CRGB::Red);
        return true;
    }
};

#endif
