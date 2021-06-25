#include "FastLED.h"
#include "Light.h"
#include "FastLedLight.h"

#define NUM_LEDS 5 //71
#define PIN 6

#define NUM_LEDS2 143
#define PIN2 8

// the debounce time; increase if the output flickers
unsigned long debounceDelay = 50;

// Light lights1(2, 5, false);
// Light lights2(3, 7, false);
FastLedLight lights3(2 /*9*/, false, 0, NUM_LEDS);
// FastLedLight lights4(10, false, NUM_LEDS, NUM_LEDS2);

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("started");

  // lights1.init();
  // lights2.init();
  lights3.init<PIN>();
  // lights4.init<PIN2>();
}

void loop()
{
  // readButton3(lights1);
  // readButton3(lights2);
  readButton3(lights3);
  // readButton3(lights4);
}

void readButton3(ILight &model)
{
  // read the state of the switch into a local variable:
  int reading = model.readButtonState();

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != model.lastButtonState)
  {
    // reset the debouncing timer
    model.lastDebounceTime = millis();
  }

  if ((millis() - model.lastDebounceTime) > debounceDelay)
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != model.buttonState)
    {
      model.buttonState = reading;

      // only toggle the lights if the new button state is HIGH
      if (model.buttonState)
      {
        model.set(!model.lightsState);
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  model.lastButtonState = reading;
}
