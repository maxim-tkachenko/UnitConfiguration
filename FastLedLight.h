#ifdef __AVR

#ifndef FastLedLight_h
#define FastLedLight_h

#include "ILight.h"
#include "FastLED.h"

class FastLedLight : public ILight
{
private:
  int _ledStripLenth;
  CRGB *_leds;
  CLEDController *_controller;

  void switchLed(bool state, int ledStripStart, int ledStripLenth);
  void setColor(CRGB color, int ledStripStart, int ledStripLenth);
  void fillOne(CRGB color, int ledStripStart, int ledStripLenth);

public:
  FastLedLight(bool initialState, int ledStripLenth);
  virtual ~FastLedLight();

  template <uint8_t DATA_PIN>
  static FastLedLight *create(bool initialState, int ledStripLenth)
  {
    auto fll = new FastLedLight(initialState, ledStripLenth);
    fll->init<DATA_PIN>();

    return fll;
  }

  //template <ESPIChipsets CHIPSET, uint8_t DATA_PIN, EOrder RGB_ORDER>
  template <uint8_t DATA_PIN>
  void init()
  {
    log("FastLedLight:init s");

    _controller = &FastLED.addLeds<WS2812B, DATA_PIN, GRB>(_leds, _ledStripLenth);
    ILight::init();

    log("FastLedLight:init e");
  }

  void set(bool state);
};

#endif
#endif