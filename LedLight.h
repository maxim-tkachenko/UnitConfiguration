#include "ILight.h"
#include "FastLED.h"

#ifndef LedLight_h
#define LedLight_h

class LedLight : public ILight {
  private:
    CLEDController *controller;

    void switchLed(bool state, int ledStripStart, int ledStripLenth);
    void setColor(CRGB color, int ledStripStart, int ledStripLenth);
    void fillOne(CRGB color, int ledStripStart, int ledStripLenth);

  public:
    int ledStripStart;
    int ledStripLenth;
    CRGB *leds;
    //CRGB leds[5];

    LedLight(
      int buttonPin,
      bool initialState,
      int ledStripStart,
      int ledStripLenth);

    ~LedLight();

    //template <ESPIChipsets CHIPSET, uint8_t DATA_PIN, EOrder RGB_ORDER>
    template<uint8_t DATA_PIN>
    void init(int nLedsOrOffset) {
      log("LedLight:init s");

      controller = &FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, ledStripLenth);
      ILight::init();

      log("LedLight:init e");
    }

    virtual void set(bool state);
};

#endif
