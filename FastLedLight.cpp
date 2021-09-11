#include "FastLedLight.h"

#ifdef FastLedLightFake_h
void fill_solid(struct CRGB *leds, int numToFill, const struct CRGB &color)
{
  traceme;

  // suppress warnings
  (void)leds;
  (void)numToFill;
  (void)color;
}

void delay(unsigned long ms)
{
  traceme;

  (void)ms;
}
#endif

FastLedLight::FastLedLight(int ledStripLength, IAnimation<FastLedLight> *animation, bool initialState)
    : IDevice(animation, initialState),
      _ledStripLength(ledStripLength),
      _leds(new CRGB[_ledStripLength])
{
  traceme;

  if (animation != nullptr)
  {
    animation->init(this);
  }
}

FastLedLight::FastLedLight(int ledStripLength, bool initialState)
    : FastLedLight(ledStripLength, nullptr, initialState)
{
  traceme;
}

FastLedLight::~FastLedLight()
{
  traceme;

  delete[] _leds;
}

void FastLedLight::setImpl(bool state)
{
  traceme;

  switchLed(state, 0, _ledStripLength);
}

void FastLedLight::switchLed(bool state, int ledStripStart, int ledStripLength)
{
  traceme;

  if (state)
  {
    //FastLED.setBrightness(16);
    //FastLED.setTemperature(Candle);
    setColor(CRGB::Green, ledStripStart, ledStripLength);
  }
  else
  {
    //    if (ledStripStart > 0)
    //      FastLED[1].clear();
    //    else
    //      FastLED[0].clear();
    setColor(CRGB::Red, ledStripStart, ledStripLength);
  }
}

void FastLedLight::setColor(CRGB color, int ledStripStart, int ledStripLength)
{
  traceme;

  fillOne(color, ledStripStart, ledStripLength);
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

void FastLedLight::fillOne(CRGB color, int ledStripStart, int ledStripLength)
{
  traceme;

  (void)ledStripStart; // suppress warning

  //  if (ledStripStart > 0)
  //  {
  //    fill_solid(leds2, ledStripLength, color);
  //    FastLED[1].showLeds(255);
  //  }
  //  else
  //  {
  //    fill_solid(leds1, ledStripLength, color);
  //    FastLED[0].showLeds(255);
  //  }

  fill_solid(_leds, ledStripLength, color);

  ledController->showLeds(1);
}
