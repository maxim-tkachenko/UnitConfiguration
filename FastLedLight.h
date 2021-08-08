#ifndef FastLedLight_h
#define FastLedLight_h

#include "_uint8_t.h"
#include "ILight.h"
#include "Diagnostics.h"

#ifdef __AVR
#include "FastLED.h"
#else

#ifndef FastLedLightFake_h
#define FastLedLightFake_h

struct CRGB
{
  static CRGB Green;
  static CRGB Red;
};

class CLEDController
{
public:
  void showLeds(uint8_t brightness = 255)
  {
    traceme;
  }
};

void fill_solid(struct CRGB *leds, int numToFill, const struct CRGB &color);
#endif
#endif

class FastLedLight : public ILight
{
private:
  int _ledStripLenth;
  CRGB *_leds;
  CLEDController *_controller = nullptr;

  void switchLed(bool state, int ledStripStart, int ledStripLenth);
  void setColor(CRGB color, int ledStripStart, int ledStripLenth);
  void fillOne(CRGB color, int ledStripStart, int ledStripLenth);

public:
  FastLedLight(int ledStripLenth, bool initialState = false);
  virtual ~FastLedLight();

  template <uint8_t DATA_PIN>
  static FastLedLight *create(int ledStripLenth, bool initialState = false)
  {
    auto fll = new FastLedLight(ledStripLenth, initialState);
    fll->init<DATA_PIN>();

    return fll;
  }

  //template <ESPIChipsets CHIPSET, uint8_t DATA_PIN, EOrder RGB_ORDER>
  template <uint8_t DATA_PIN>
  void init()
  {
    traceme;

    _controller =
#ifdef __AVR
        &FastLED.addLeds<WS2812B, DATA_PIN, GRB>(_leds, _ledStripLenth);
#else
        new CLEDController();
#endif

    ILight::init();
  }

  void set(bool state);
};

#endif
