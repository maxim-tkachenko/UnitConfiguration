#include "Arduino.h"
#include "Runner.cpp"
// #include "ArduinoTrace.h"

Runner runner;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("started4");
  // Serial.println(__func__);
  // Serial.println(__FUNCTION__);
  // Serial.println(__PRETTY_FUNCTION__);

  runner.setup();
}

void loop()
{
  runner.loop();
}
