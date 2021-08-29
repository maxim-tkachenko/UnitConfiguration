#ifndef FastLedLight_h
#define FastLedLight_h

#include "_uint8_t.h"
#include "IDevice.h"
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

    (void)brightness; // suppress warning
  }
};

void fill_solid(struct CRGB *leds, int numToFill, const struct CRGB &color);
#endif
#endif

class FastLedLight : public IDevice
{
private:
  int _ledStripLength;
  CRGB *_leds;
  CLEDController *_controller = nullptr;

  void switchLed(bool state, int ledStripStart, int ledStripLength);
  void setColor(CRGB color, int ledStripStart, int ledStripLength);
  void fillOne(CRGB color, int ledStripStart, int ledStripLength);

public:
  FastLedLight(int ledStripLength, bool initialState = false);
  virtual ~FastLedLight();

  template <uint8_t DATA_PIN>
  static FastLedLight *create(int ledStripLength, bool initialState = false)
  {
    auto fll = new FastLedLight(ledStripLength, initialState);
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
        &FastLED.addLeds<WS2812B, DATA_PIN, GRB>(_leds, _ledStripLength);
#else
        new CLEDController();
#endif

    IDevice::init();
  }

  void set(bool state);
};

#endif
