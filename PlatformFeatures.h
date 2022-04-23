#ifndef PlatformFeatures_h
#define PlatformFeatures_h

#include "_uint8_t.h"
#include "DiagnosticsFlags.h"
#include "Definitions.h"

#if REAL_BOARD
#include "Arduino.h"
#else
#include <iostream>
using namespace std;
#endif

class PlatformFeatures
{
public:
    static void init();
    static void print(const char c[]);
    static void println(const char c[]);
    static int ledPin();
    static void pinIn(uint8_t pin, bool pullup = false);
    static void pinOut(uint8_t pin);
    static void digitalSet(uint8_t pin, uint8_t value);
    static int digitalGet(uint8_t pin);
    static unsigned long milliseconds();
};

#endif