#include "FastLedLight.h"
#include "FastLED.h"

FastLedLight::FastLedLight(bool initialState, int ledStripLenth)
    : ILight(initialState)
{
  this->ledStripLenth = ledStripLenth;
  this->leds = new CRGB[ledStripLenth];
}

FastLedLight::~FastLedLight()
{
  delete[] leds;
}

void FastLedLight::set(bool state)
{
  log("FastLedLight::set s");

  switchLed(state, 0, ledStripLenth);
  ILight::set(state);

  log("FastLedLight:set e");
}

void FastLedLight::switchLed(bool state, int ledStripStart, int ledStripLenth)
{
  log("FastLedLight::switchLed s");
  if (state)
  {
    //FastLED.setBrightness(16);
    //FastLED.setTemperature(Candle);
    setColor(CRGB::Green, ledStripStart, ledStripLenth);
  }
  else
  {
    //    if (ledStripStart > 0)
    //      FastLED[1].clear();
    //    else
    //      FastLED[0].clear();
    setColor(CRGB::Red, ledStripStart, ledStripLenth);
  }
  log("FastLedLight::switchLed e");
}

void FastLedLight::setColor(CRGB color, int ledStripStart, int ledStripLenth)
{
  fillOne(color, ledStripStart, ledStripLenth);
  return;

  /*
    if (color.r == 0 && color.g == 0 && color.b == 0)
    {
      FastLED.clear(true);
    }
    else
    {
      int ledLeftCenterIndex = NUM_LEDS / 2 - 3 - 1;
      int ledRightCenterIndex = NUM_LEDS2 / 2 + 6 - 1;
      int speed = 3;

      if (ledStripStart > 0)
      {
        // from right to left
        for (int i = 0; i < ledRightCenterIndex; i++)
        {
          leds2[ledRightCenterIndex - i] = color;
          int b = ledRightCenterIndex + i;
          if (b < NUM_LEDS2)
            leds2[b] = color;

          FastLED[1].showLeds(255);
          FastLED.delay(speed);
        }

        for (int i = NUM_LEDS - 1; i >= 0; i--)
        {
          leds1[i] = color;
          FastLED[0].showLeds(255);
          FastLED.delay(speed);
        }
      }
      else
      {
        // from left to right
      }
    }*/
}

void FastLedLight::fillOne(CRGB color, int ledStripStart, int ledStripLenth)
{
  //  if (ledStripStart > 0)
  //  {
  //    fill_solid(leds2, ledStripLenth, color);
  //    FastLED[1].showLeds(255);
  //  }
  //  else
  //  {
  //    fill_solid(leds1, ledStripLenth, color);
  //    FastLED[0].showLeds(255);
  //  }

  log("FastLedLight::fillOne s");

  fill_solid(leds, ledStripLenth, color);

  log("FastLedLight::fillOne s1");

  controller->showLeds(1);

  log("FastLedLight::fillOne e");
}
