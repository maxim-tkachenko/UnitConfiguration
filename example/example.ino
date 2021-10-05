#include "TestConfiguration.h"
#include "DebugConfiguration.h"
#include "SwitchReedConfiguration.h"

Runner runner;

void setup()
{
  runner.init();
  runner.setConfig(new SwitchReedConfiguration());
}

void loop()
{
  runner.loop();
}
