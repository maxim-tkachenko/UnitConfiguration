#include "FastLED.h"
#include "LightsModel.h"

#define NUM_LEDS 80
#define PIN 6

#define NUM_LEDS2 160
#define PIN2 8

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS2];

const int ledPin = 13;
unsigned long debounceDelay = 50; // the debounce time; increase if the output flickers

LightsModel lights1(2, 5, LOW, false, 0, 0);
LightsModel lights2(3, 7, LOW, false, 0, 0);
LightsModel lights3(9, 222, LOW, true, 0, NUM_LEDS);
LightsModel lights4(10, 222, LOW, true, NUM_LEDS, NUM_LEDS2);

void setup()
{
  pinMode(ledPin, OUTPUT);
  FastLED.addLeds<WS2812B, PIN, GRB>(leds1, NUM_LEDS);
  FastLED.addLeds<WS2812B, PIN2, GRB>(leds2, NUM_LEDS2);

  init(lights1);
  init(lights2);
  init(lights3);
  init(lights4);
}

void init(LightsModel model)
{
  pinMode(model.buttonPin, INPUT);

  pinMode(model.relayPin, OUTPUT);
  switchRelay(model.relayPin, model.lightsState);

  if (model.withLed)
    switchLed(model.lightsState, model.ledStripStart, model.ledStripLenth);
}

void loop()
{
  readButton3(lights1);
  readButton3(lights2);
  readButton3(lights3);
  readButton3(lights4);
}

void readButton3(LightsModel &model)
{
  // read the state of the switch into a local variable:
  int reading = digitalRead(model.buttonPin);

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
      if (model.buttonState == HIGH)
      {
        model.lightsState = !model.lightsState;

        if (model.withLed)
          switchLed(model.lightsState, model.ledStripStart, model.ledStripLenth);
      }
    }
  }

  // set the lights:
  switchRelay(model.relayPin, model.lightsState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  model.lastButtonState = reading;
}

void switchRelay(int pin, bool state)
{
  digitalWrite(pin, state);
  digitalWrite(ledPin, state);
}

void switchLed(bool state, int ledStripStart, int ledStripLenth)
{
  if (state)
  {
    //FastLED.setBrightness(16);
    //FastLED.setTemperature(Candle);
    setColor(CRGB::White, ledStripStart, ledStripLenth);
  }
  else
  {
    //    if (ledStripStart > 0)
    //      FastLED[1].clear();
    //    else
    //      FastLED[0].clear();
    setColor(CRGB::Black, ledStripStart, ledStripLenth);
  }
}

void setColor(CRGB color, int ledStripStart, int ledStripLenth)
{
  if (ledStripStart > 0)
  {
    fill_solid(leds2, NUM_LEDS2, color);
    FastLED[1].showLeds(255);
  }
  else
  {
    fill_solid(leds1, NUM_LEDS, color);
    FastLED[0].showLeds(255);
  }
}
