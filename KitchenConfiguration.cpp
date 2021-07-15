#ifndef KitchenConfiguration_cpp
#define KitchenConfiguration_cpp

#include "IConfiguration.h"
#include "FastLedLight.h"
#include "ButtonDebounced.h"

class KitchenConfiguration : public IConfiguration<1>
{
#define NUM_LEDS 5 //71
#define LED1_PIN 6

#define NUM_LEDS2 143
#define LED2_PIN 8

private:
    // Light lights1(2, 5, false);
    // Light lights2(3, 7, false);
    // FastLedLight lights4(10, false, NUM_LEDS, NUM_LEDS2);

public:
    KitchenConfiguration()
    {
        AVRPlatform platform;
        platform.print(__PRETTY_FUNCTION__);

        units[0] = new LightUnit(
            new ButtonDebounced(2 /*9*/),
            FastLedLight::create<LED1_PIN>(false, NUM_LEDS));

        // lights1.init();
        // lights2.init();
        // lights4.init<LED2_PIN>();
    }
};

#endif
