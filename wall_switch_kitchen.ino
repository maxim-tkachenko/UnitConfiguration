#include "Runner.cpp"
// #include "ArduinoTrace.h"

#define __AVR

Runner runner;

void setup()
{
  // for some reason is not initialized from AVRPlatform
  Serial.begin(9600);
  while (!Serial)
    ;

  // Serial.println(__func__);
  // Serial.println(__FUNCTION__);
  // Serial.println(__PRETTY_FUNCTION__);

  runner.setup();
}

void loop()
{
  runner.loop();
}
