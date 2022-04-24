#ifndef SwitchReedConfiguration_h
#define SwitchReedConfiguration_h

#include <UnitConfiguration.h>
#include <TimeoutHandler.h>
#include <LedGuard.h>
#include "LeftLedTurnConfig.h"
#include "LeftLedAnimation.h"
#include "BathroomControllerHandler.h"

class SwitchReedConfiguration : public IConfiguration<1>
{
public:
    SwitchReedConfiguration()
    {
        auto led = FastLedLight::create<6>(5, new LeftLedTurnConfig());
        auto fan = new GenericDevice(5);

        add(
            new WorkUnit(
                new IDevice *[2]
                {
                    led,
                        fan,
                },
                2,
                new IController *[2]
                {
                    new PushButtonDebounced(11, WALL_SWITCH_ID),
                        new SwitchButton(12, DOOR_REED_SWITCH_ID),
                },
                2,
                new IHandler *[3]
                {
                    new BathroomControllerHandler(),
                        new LedGuard(0, 5000),
                        new TimeoutHandler(0, 15000),
                },
                3));
    }
};

#endif
