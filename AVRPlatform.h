#ifndef AVRPlatform_h
#define AVRPlatform_h

#include "IPlatform.h"

class AVRPlatform : public IPlatform
{
public:
    static void init()
    {
#ifdef __AVR
        Serial.begin(9600);
        while (!Serial)
            ;

#ifdef TRACE_ENABLED
        Serial.println("v0.8");
        Serial.print("TRACE: ");
        Serial.println(__PRETTY_FUNCTION__);
#endif
#endif
    }

    virtual ~AVRPlatform();
    void print(const char c[]);
    void println(const char c[]);
    int ledPin();
    void pinIn(uint8_t pin);
    void pinOut(uint8_t pin);
    void digitalSet(uint8_t pin, uint8_t value);
    int digitalGet(uint8_t pin);
    unsigned long milliseconds();
};

#endif