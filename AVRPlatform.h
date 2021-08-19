#ifndef AVRPlatform_h
#define AVRPlatform_h

#include "_uint8_t.h"
#include "DiagnosticsFlags.h"

#ifdef __AVR
#include "Arduino.h"
#else
#include <iostream>
using namespace std;
#endif

class AVRPlatform
{
public:
    static void init()
    {
#ifdef __AVR
        Serial.begin(9600);
        while (!Serial)
            ;

#ifdef TRACE_ENABLED
        Serial.println("v0.9");
        Serial.print("TRACE: ");
        Serial.println(__PRETTY_FUNCTION__);
#endif
#endif
    }

    static void print(const char c[]);
    static void println(const char c[]);
    static int ledPin();
    static void pinIn(uint8_t pin);
    static void pinOut(uint8_t pin);
    static void digitalSet(uint8_t pin, uint8_t value);
    static int digitalGet(uint8_t pin);
    static unsigned long milliseconds();
};

#endif