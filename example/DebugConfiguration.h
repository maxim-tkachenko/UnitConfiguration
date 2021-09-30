#ifndef DebugConfiguration_h
#define DebugConfiguration_h

#include <UnitConfiguration.h>
#include <TimeoutHandler.h>
#include <LedGuard.h>
#include "LeftLedTurnConfig.h"
#include "LeftLedAnimation.h"

class DebugConfiguration : public IConfiguration<2>
{
public:
    DebugConfiguration()
    {
        auto leftLed = FastLedLight::create<6>(5, new LeftLedTurnConfig(), new LeftLedAnimation());
        auto rightLed = new GenericDevice(5);

        add(
            new WorkUnit(
                new IDevice *[2]
                {
                    leftLed,
                        rightLed,
                },
                2,
                new PushButtonDebounced(9, LEFT_LED_BUTTON_ID),
                new IHandler *[3]
                {
                    new ControllerHandler(),
                        new LedGuard(0, 5000),
                        new TimeoutHandler(0, 15000),
                },
                3));

        add(
            new WorkUnit(
                new IDevice *[2]
                {
                    rightLed,
                        leftLed,
                },
                2,
                // new PushButtonDebounced(11, RIGHT_LED_BUTTON_ID)));
                new SwitchButton(12, RIGHT_LED_BUTTON_ID)));
    }
};

#endif
