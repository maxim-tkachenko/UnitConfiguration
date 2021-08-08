#include "FastLedLight.h"

#ifdef FastLedLightFake_h
void fill_solid(struct CRGB *leds, int numToFill, const struct CRGB &color)
{
}
#endif

FastLedLight::FastLedLight(int ledStripLenth, bool initialState)
    : ILight(initialState),
      _ledStripLenth(ledStripLenth),
      _leds(new CRGB[_ledStripLenth])
{
  traceme;
}

FastLedLight::~FastLedLight()
{
  traceme;

  delete[] _leds;
}

void FastLedLight::set(bool state)
{
  traceme;

  switchLed(state, 0, _ledStripLenth);
  ILight::set(state);
}

void FastLedLight::switchLed(bool state, int ledStripStart, int ledStripLenth)
{
  traceme;

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

  traceme;

  fill_solid(_leds, ledStripLenth, color);

  _controller->showLeds(1);
}
