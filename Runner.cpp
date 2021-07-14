#ifndef Runner_cpp
#define Runner_cpp

#ifdef __AVR
#include "FastLedLight.h"
#else
#include "Light.h"
#endif
#include "ButtonDebounced.h"
#include "LightUnit.h"
#include "AVRPlatform.h"

class Runner
{
#define NUM_LEDS 5 //71
#define LED1_PIN 6

#define NUM_LEDS2 143
#define LED2_PIN 8

private:
    AVRPlatform _platform;

    // Light lights1(2, 5, false);
    // Light lights2(3, 7, false);
    LightUnit *lightUnit3;
    // FastLedLight lights4(10, false, NUM_LEDS, NUM_LEDS2);

public:
    ~Runner()
    {
        _platform.print(__PRETTY_FUNCTION__);
        delete lightUnit3;
    }

    void setup()
    {
        _platform.print("v0.5");
        _platform.print(__PRETTY_FUNCTION__);

        lightUnit3 = new LightUnit(
            new ButtonDebounced(2 /*9*/),
#ifdef __AVR
            FastLedLight::create<LED1_PIN>(false, NUM_LEDS)
#else
            new Light(LED1_PIN, false)
#endif
        );

        // lights1.init();
        // lights2.init();
        // lights4.init<LED2_PIN>();
    }

    void loop()
    {
        // _platform.print(__PRETTY_FUNCTION__);
        lightUnit3->check();

        // readButton3(lights1);
        // readButton3(lights2);
        // readButton3(lights4);
    }
};

#endif
