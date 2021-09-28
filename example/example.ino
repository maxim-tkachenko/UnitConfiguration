#include "TestConfiguration.h"
#include "DebugConfiguration.h"

Runner runner;

void setup()
{
  runner.init();
  runner.setConfig(new DebugConfiguration());
}

void loop()
{
  runner.loop();
}
