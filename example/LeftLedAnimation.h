#ifndef LeftLedAnimation_h
#define LeftLedAnimation_h

#include <UnitConfiguration.h>

#define LEFT_LED_BUTTON_ID 100
#define RIGHT_LED_BUTTON_ID 101

class LeftLedAnimation : public IDeviceTurnConfiguration<FastLedLight>
{
private:
    unsigned long _delay = 100;

    void animateForward(CRGB color)
    {
        for (int i = 0; i < _device->ledController->size(); i++)
        {
            if (i != 0)
            {
                delay(_delay);
            }

            _device->ledController->leds()[i] = color;
            _device->ledController->showLeds(1);
        }
    }

    void animateBack(CRGB color)
    {
        for (int i = _device->ledController->size() - 1; i >= 0; i--)
        {
            _device->ledController->leds()[i] = color;
            _device->ledController->showLeds(1);

            if (i != 0)
            {
                delay(_delay);
            }
        }
    }

public:
    LeftLedAnimation()
    {
        traceme;
    }

    bool on(uint8_t requestorId) override
    {
        traceme;

        if (requestorId == 0 ||
            requestorId == LEFT_LED_BUTTON_ID)
        {
            animateForward(CRGB::Green);
        }
        else if (requestorId == RIGHT_LED_BUTTON_ID)
        {
            animateBack(CRGB::Green);
        }
        else
        {
            return false;
        }

        return true;
    }

    bool off(uint8_t requestorId) override
    {
        traceme;

        if (requestorId == 0 ||
            requestorId == LEFT_LED_BUTTON_ID)
        {
            animateForward(CRGB::Red);
        }
        else if (requestorId == RIGHT_LED_BUTTON_ID)
        {
            animateBack(CRGB::Red);
        }
        else
        {
            return false;
        }

        return true;
    }
};

#endif
