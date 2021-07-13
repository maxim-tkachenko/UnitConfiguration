#ifndef __AVR

#include <iostream>
#include "Runner.cpp"

using namespace std;

Runner runner;

int main()
{
    cout << "Hello World1" << std::endl;

    runner.setup();
    runner.loop();

    return 0;
}

#endif
