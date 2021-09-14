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

  fill_solid(_leds, _ledStripLength, state ? CRGB::Green : CRGB::Red);
  ledController->showLeds(1);
}
