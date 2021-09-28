#ifndef TestConfiguration_h
#define TestConfiguration_h

#include <UnitConfiguration.h>
#include <TimeoutHandler.h>

class TestConfiguration : public IConfiguration<3>
{
public:
    TestConfiguration()
    {
        // Setup primitive devices which can be controlled via relay and button, just specify data pins:
        add(new WorkUnit(new GenericDevice(2), new PushButtonDebounced(12)));

        // Setup leds using FastLED:
        add(new WorkUnit(FastLedLight::create<3>(200, nullptr), new PushButtonDebounced(11)));

        // Setup two light zones which are controlled by two buttons and turned off after 15 mins of inactivity:
        add(
            new WorkUnit(
                new IDevice *[2]
                {
                    new GenericDevice(4),
                        new GenericDevice(5),
                },
                2,
                new IController *[2]
                {
                    new PushButtonDebounced(10),
                        new PushButtonDebounced(9),
                },
                2,
                new TimeoutHandler(1000 * 60 * 15))); // 15 mins
    }
};

#endif
