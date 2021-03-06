#ifndef FastLedLight_h
#define FastLedLight_h

#include "_uint8_t.h"
#include "IDevice.h"
#include "Diagnostics.h"
#include "Definitions.h"

#if REAL_BOARD
#include "FastLED.h"
#else

#ifndef FastLedLightFake_h
#define FastLedLightFake_h

struct CRGB
{
  static CRGB Green;
  static CRGB Red;
  static CRGB White;
  static CRGB Blue;
  static CRGB Black;
};

typedef enum
{
  Candle
} ColorTemperature;

class CLEDController
{
private:
  int _size;

public:
  CLEDController(int size) : _size(size)
  {
    traceme;
  }

  void showLeds(uint8_t brightness = 255)
  {
    traceme;

    (void)brightness; // suppress warning
  }

  int size()
  {
    return _size;
  }

  CRGB *leds()
  {
    return new CRGB[size()];
  }

  void clearLedData() {}

  void clearLeds(int nLeds)
  {
    (void)nLeds;
  }

  CLEDController &setTemperature(ColorTemperature temperature)
  {
    (void)temperature;

    return *this;
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

public:
  CLEDController *ledController = nullptr;

  FastLedLight(
      int ledStripLength,
      IDeviceTurnConfiguration<FastLedLight> *config,
      IDeviceTurnConfiguration<FastLedLight> *animation = nullptr,
      bool initialState = false);
  virtual ~FastLedLight();

  // TODO: to templated class
  template <uint8_t DATA_PIN>
  static FastLedLight *create(
      int ledStripLength,
      IDeviceTurnConfiguration<FastLedLight> *config,
      IDeviceTurnConfiguration<FastLedLight> *animation = nullptr,
      bool initialState = false)
  {
    auto fll = new FastLedLight(ledStripLength, config, animation, initialState);
    fll->init<DATA_PIN>();

    return fll;
  }

  // template <ESPIChipsets CHIPSET, uint8_t DATA_PIN, EOrder RGB_ORDER>
  template <uint8_t DATA_PIN>
  void init()
  {
    traceme;

    ledController =
#if REAL_BOARD
        &FastLED.addLeds<WS2812B, DATA_PIN, GRB>(_leds, _ledStripLength);
#else
        new CLEDController(_ledStripLength);
#endif

    IDevice::init();
  }
};

#endif
