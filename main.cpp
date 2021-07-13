#ifndef __AVR

#include "Runner.cpp"

Runner runner;

int main()
{
    runner.setup();
    runner.loop();

    return 0;
}

#endif
