#include "TestConfiguration.h"

Runner runner;

void setup()
{
  runner.init();
  runner.setConfig(new TestConfiguration());
}

void loop()
{
  runner.loop();
}
