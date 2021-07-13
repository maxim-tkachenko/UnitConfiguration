#ifdef __AVR
#include "FastLedLight.h"
#else
#include "Light.h"
#endif
#include "ButtonDebounced.h"
#include "LightUnit.h"

#ifndef Runner_cpp
#define Runner_cpp

class Runner
{
#define NUM_LEDS 5 //71
#define LED1_PIN 6

#define NUM_LEDS2 143
#define LED2_PIN 8

private:
    // Light lights1(2, 5, false);
    // Light lights2(3, 7, false);
    LightUnit *lightUnit3;
    // FastLedLight lights4(10, false, NUM_LEDS, NUM_LEDS2);

public:
    ~Runner()
    {
        delete lightUnit3;
    }

    void setup()
    {
        auto *light =
#ifdef __AVR
            FastLedLight::create<LED1_PIN>(false, NUM_LEDS);
#else
            new Light(444, false);
        light->init();
#endif
        lightUnit3 = new LightUnit(new ButtonDebounced(2 /*9*/), light);

        // lights1.init();
        // lights2.init();
        // lights4.init<LED2_PIN>();
    }

    void loop()
    {
        lightUnit3->check();

        // readButton3(lights1);
        // readButton3(lights2);
        // readButton3(lights4);
    }
};

#endif
