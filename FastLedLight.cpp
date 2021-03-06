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

FastLedLight::FastLedLight(
    int ledStripLength,
    IDeviceTurnConfiguration<FastLedLight> *config,
    IDeviceTurnConfiguration<FastLedLight> *animation,
    bool initialState)
    : IDevice(config, animation, initialState),
      _ledStripLength(ledStripLength),
      _leds(new CRGB[_ledStripLength])
{
  traceme;

  initConfigs<FastLedLight>(config, animation, this);
}

FastLedLight::~FastLedLight()
{
  traceme;

  delete[] _leds;
}
