#include "FastLED.h"
#include "Light.h"
#include "LedLight.h"

#define NUM_LEDS 71
#define PINNN 6

#define NUM_LEDS2 143
#define PIN2 8

//CRGB leds1[NUM_LEDS];
//CRGB leds2[NUM_LEDS2];

//const int ledPin = 13;
unsigned long debounceDelay = 50;  // the debounce time; increase if the output flickers

#define lights3InitialState true
Light lights1(2, 5, LOW);
Light lights2(3, 7, LOW);
LedLight lights3(2/*9*/, false, 0, 5);  //NUM_LEDS);
LedLight lights4(10, LOW, NUM_LEDS, NUM_LEDS2);

// CLEDController *controller;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("started");

  //  pinMode(ledPin, OUTPUT);
  //  FastLED.addLeds<WS2812B, PIN, GRB>(leds1, NUM_LEDS);
  //  FastLED.addLeds<WS2812B, PIN2, GRB>(leds2, NUM_LEDS2);
  //
  //  init(lights1);
  //  init(lights2);
  //  init(lights3);
  //  init(lights4);

  //controller = &FastLED.addLeds<WS2812B, PIN, GRB>(lights3.leds, NUM_LEDS);
  //FastLED.addLeds<WS2812B, PIN2, GRB>(lights3.leds, NUM_LEDS2);

  //lights1.init();
  //lights2.init();
  //lights3.init<WS2812B, PINNN, GRB>(NUM_LEDS);
  // lights4.init<WS2812B, 5, GRB>(NUM_LEDS2);

  lights3.init<PINNN>(3);
  //lights3.set(false);
}

//void init(ILight model)
//{
//  pinMode(model.buttonPin, INPUT);
//
//  pinMode(model.relayPin, OUTPUT);
//  switchRelay(model.relayPin, model.lightsState);
//
//  if (model.withLed)
//    switchLed(model.lightsState, model.ledStripStart, model.ledStripLenth);
//}

void loop() {
  // readButton3(lights1);
  // readButton3(lights2);
  readButton3(lights3);
  // readButton3(lights4);
}

void readButton3(ILight &model) {
  // read the state of the switch into a local variable:
  int reading = digitalRead(model.buttonPin);
  //Serial.println(reading);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != model.lastButtonState) {
    // reset the debouncing timer
    model.lastDebounceTime = millis();
  }

  if ((millis() - model.lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != model.buttonState) {
      model.buttonState = reading;

      // only toggle the lights if the new button state is HIGH
      if (model.buttonState == HIGH) {
        Serial.println("button detected");
        //        model.lightsState = !model.lightsState;
        //
        //        if (model.withLed)
        //          switchLed(model.lightsState, model.ledStripStart, model.ledStripLenth);

        model.set(!model.lightsState);
      }
    }
  }

  //  // set the lights:
  //  switchRelay(model.relayPin, model.lightsState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  model.lastButtonState = reading;
}

//void switchRelay(int pin, bool state)
//{
//  digitalWrite(pin, state);
//  digitalWrite(ledPin, state);
//}

//void switchLed(bool state, int ledStripStart, int ledStripLenth)
//{
//  if (state)
//  {
//    //FastLED.setBrightness(16);
//    //FastLED.setTemperature(Candle);
//    setColor(CRGB::White, ledStripStart, ledStripLenth);
//  }
//  else
//  {
//    //    if (ledStripStart > 0)
//    //      FastLED[1].clear();
//    //    else
//    //      FastLED[0].clear();
//    setColor(CRGB::Black, ledStripStart, ledStripLenth);
//  }
//}
//
//void setColor(CRGB color, int ledStripStart, int ledStripLenth)
//{
//  fillOne(color, ledStripStart, ledStripLenth);
//  return;
//
//  if (color.r == 0 && color.g == 0 && color.b == 0)
//  {
//    FastLED.clear(true);
//  }
//  else
//  {
//    int ledLeftCenterIndex = NUM_LEDS / 2 - 3 - 1;
//    int ledRightCenterIndex = NUM_LEDS2 / 2 + 6 - 1;
//    int speed = 3;
//
//    if (ledStripStart > 0)
//    {
//      // from right to left
//      for (int i = 0; i < ledRightCenterIndex; i++)
//      {
//        leds2[ledRightCenterIndex - i] = color;
//        int b = ledRightCenterIndex + i;
//        if (b < NUM_LEDS2)
//          leds2[b] = color;
//
//        FastLED[1].showLeds(255);
//        FastLED.delay(speed);
//      }
//
//      for (int i = NUM_LEDS - 1; i >= 0; i--)
//      {
//        leds1[i] = color;
//        FastLED[0].showLeds(255);
//        FastLED.delay(speed);
//      }
//    }
//    else
//    {
//      // from left to right
//    }
//  }
//}
//
//void fillOne(CRGB color, int ledStripStart, int ledStripLenth)
//{
//  if (ledStripStart > 0)
//  {
//    fill_solid(leds2, NUM_LEDS2, color);
//    FastLED[1].showLeds(255);
//  }
//  else
//  {
//    fill_solid(leds1, NUM_LEDS, color);
//    FastLED[0].showLeds(255);
//  }
//}
