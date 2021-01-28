#include "FastLED.h"

#define NUM_LEDS 80
#define PIN 6

#define NUM_LEDS2 160
#define PIN2 8

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS2];

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2; // the number of the pushbutton pin
const int buttonPin2 = 3;
const int ledPin = 13; // the number of the LED pin

const int buttonPinL1 = 9;
const int buttonPinL2 = 10;

// Variables will change:
bool lightsState = LOW; // the current state of the output pin
bool lightsState2 = LOW;
bool buttonState; // the current reading from the input pin
bool buttonState2;
bool lastButtonState = LOW; // the previous reading from the input pin
bool lastButtonState2 = LOW;

bool lightsStateL1 = LOW; // the current state of the output pin
bool lightsStateL2 = LOW;
bool buttonStateL1; // the current reading from the input pin
bool buttonStateL2;
bool lastButtonStateL1 = LOW; // the previous reading from the input pin
bool lastButtonStateL2 = LOW;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTimeL1 = 0;
unsigned long lastDebounceTimeL2 = 0;
unsigned long debounceDelay = 50; // the debounce time; increase if the output flickers

const int r1Pin = 5;
const int r2Pin = 7;

void setup()
{
  pinMode(ledPin, OUTPUT);
  FastLED.addLeds<WS2812B, PIN, GRB>(leds1, NUM_LEDS);
  FastLED.addLeds<WS2812B, PIN2, GRB>(leds2, NUM_LEDS2);

  init(buttonPin, r1Pin, lightsState, false, 0, 0);
  init(buttonPin2, r2Pin, lightsState2, false, 0, 0);
  init(buttonPinL1, 22, lightsStateL1, true, 0, NUM_LEDS);
  init(buttonPinL2, 22, lightsStateL2, true, NUM_LEDS, NUM_LEDS2);
}

void init(int buttonPin,
          int relayPin,
          bool lightsState,
          bool withLed,
          int ledStripStart,
          int ledStripLenth)
{
  pinMode(buttonPin, INPUT);

  pinMode(relayPin, OUTPUT);
  switchRelay(relayPin, lightsState);

  if (withLed)
    switchLed(lightsState, ledStripStart, ledStripLenth);
}

void loop()
{
  readButton3(buttonPin, r1Pin, lightsState, buttonState, lastButtonState, lastDebounceTime, false, 0, 0);
  readButton3(buttonPin2, r2Pin, lightsState2, buttonState2, lastButtonState2, lastDebounceTime2, false, 0, 0);
  readButton3(buttonPinL1, r2Pin, lightsStateL1, buttonStateL1, lastButtonStateL1, lastDebounceTimeL1, true, 0, NUM_LEDS);
  readButton3(buttonPinL2, r2Pin, lightsStateL2, buttonStateL2, lastButtonStateL2, lastDebounceTimeL2, true, NUM_LEDS, NUM_LEDS2);
}

void readButton3(
  int buttonPin,
  int relayPin,
  bool & ledState,
  bool & buttonState,
  bool & lastButtonState,
  unsigned long & lastDebounceTime,
  bool withLed,
  int ledStripStart,
  int ledStripLenth)
{
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState)
  {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState)
    {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH)
      {
        ledState = !ledState;

        if (withLed)
          switchLed(ledState, ledStripStart, ledStripLenth);
      }
    }
  }

  // set the LED:
  switchRelay(relayPin, ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
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
