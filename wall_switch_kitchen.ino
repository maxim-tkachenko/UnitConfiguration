#include "Runner.h"
#include "KitchenConfiguration.cpp"
// #include "ArduinoTrace.h"

#define __AVR

Runner runner;

void setup()
{
  // Serial.println(__func__);
  // Serial.println(__FUNCTION__);
  // Serial.println(__PRETTY_FUNCTION__);

  AVRPlatform::init();
  runner.setup(new KitchenConfiguration());
}

void loop()
{
  runner.loop();
}
