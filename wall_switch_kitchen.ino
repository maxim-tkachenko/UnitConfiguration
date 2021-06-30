#include "FastLED.h"
// #include "ArduinoTrace.h"
#include "Light.h"
#include "FastLedLight.h"
#include "ButtonDebounced.h"
#include "LightUnit.h"

#define NUM_LEDS 5 //71
#define PIN 6

#define NUM_LEDS2 143
#define PIN2 8

// Light lights1(2, 5, false);
// Light lights2(3, 7, false);
// FastLedLight lights4(10, false, NUM_LEDS, NUM_LEDS2);

LightUnit *lightUnit3;
ButtonDebounced button3(2 /*9*/);
FastLedLight lights3(false, 0, NUM_LEDS);

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("started2");
  // Serial.println(__func__);
  // Serial.println(__FUNCTION__);
  // Serial.println(__PRETTY_FUNCTION__);

  lights3.init<PIN>();
  lightUnit3 = new LightUnit(button3, lights3);

  // lights1.init();
  // lights2.init();
  // lights4.init<PIN2>();
}

void loop()
{
  lightUnit3->check();

  // readButton3(lights1);
  // readButton3(lights2);
  // readButton3(lights4);
}
