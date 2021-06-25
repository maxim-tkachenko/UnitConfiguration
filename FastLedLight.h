#include "ILight.h"
#include "FastLED.h"

#ifndef FastLedLight_h
#define FastLedLight_h

class FastLedLight : public ILight
{
private:
  CLEDController *controller;

  void switchLed(bool state, int ledStripStart, int ledStripLenth);
  void setColor(CRGB color, int ledStripStart, int ledStripLenth);
  void fillOne(CRGB color, int ledStripStart, int ledStripLenth);

public:
  int ledStripStart;
  int ledStripLenth;
  CRGB *leds;

  FastLedLight(
      int buttonPin,
      bool initialState,
      int ledStripStart,
      int ledStripLenth);

  ~FastLedLight();

  //template <ESPIChipsets CHIPSET, uint8_t DATA_PIN, EOrder RGB_ORDER>
  template <uint8_t DATA_PIN>
  void init()
  {
    log("FastLedLight:init s");

    controller = &FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, ledStripLenth);
    ILight::init();

    log("FastLedLight:init e");
  }

  virtual void set(bool state);
};

#endif
