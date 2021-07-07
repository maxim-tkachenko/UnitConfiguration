#include "FastLED.h"
// #include "ArduinoTrace.h"
#include "Light.h"
#include "FastLedLight.h"
#include "ButtonDebounced.h"
#include "LightUnit.h"

#define NUM_LEDS 5 //71
#define LED1_PIN 6

#define NUM_LEDS2 143
#define LED2_PIN 8

// Light lights1(2, 5, false);
// Light lights2(3, 7, false);
LightUnit *lightUnit3;
// FastLedLight lights4(10, false, NUM_LEDS, NUM_LEDS2);

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("started3");
  // Serial.println(__func__);
  // Serial.println(__FUNCTION__);
  // Serial.println(__PRETTY_FUNCTION__);

  lightUnit3 = new LightUnit(new ButtonDebounced(2 /*9*/),
                             FastLedLight::create<LED1_PIN>(false, NUM_LEDS));

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
