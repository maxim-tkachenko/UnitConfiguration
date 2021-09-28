#include "FastLedLight.h"

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
