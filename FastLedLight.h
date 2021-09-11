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

  int size()
  {
    return 5;
  }

  CRGB *leds()
  {
    return new CRGB[size()];
  }
};

void fill_solid(struct CRGB *leds, int numToFill, const struct CRGB &color);
void delay(unsigned long ms);
#endif
#endif

class FastLedLight : public IDevice
{
private:
  int _ledStripLength;
  CRGB *_leds;

  void switchLed(bool state, int ledStripStart, int ledStripLength);
  void setColor(CRGB color, int ledStripStart, int ledStripLength);
  void fillOne(CRGB color, int ledStripStart, int ledStripLength);

protected:
  void setImpl(bool state) override;

public:
  CLEDController *_controller = nullptr;

  FastLedLight(int ledStripLength, bool initialState = false);
  FastLedLight(int ledStripLength, IAnimation<FastLedLight> *animation, bool initialState = false);
  virtual ~FastLedLight();

  template <uint8_t DATA_PIN>
  static FastLedLight *create(int ledStripLength, IAnimation<FastLedLight> *animation, bool initialState = false)
  {
    auto fll = new FastLedLight(ledStripLength, animation, initialState);
    fll->init<DATA_PIN>();

    return fll;
  }

  template <uint8_t DATA_PIN>
  static FastLedLight *create(int ledStripLength, bool initialState = false)
  {
    return create<DATA_PIN>(ledStripLength, nullptr, initialState);
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
};

#endif
