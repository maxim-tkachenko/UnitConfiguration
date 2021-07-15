#ifndef __AVR

#include "Runner.h"
#include "KitchenConfiguration.cpp"

Runner runner;

int main()
{
    runner.setup(new KitchenConfiguration());
    runner.loop();

    return 0;
}

#endif
