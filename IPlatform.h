#include "_uint8_t.h"

#ifndef IPlatform_h
#define IPlatform_h

class IPlatform
{
public:
    // virtual ~IPlatform();
    virtual void print(const char c[]) = 0;
    virtual int ledPin() = 0;
    virtual void pinIn(uint8_t pin) = 0;
    virtual void pinOut(uint8_t pin) = 0;
    virtual void digitalSet(uint8_t pin, uint8_t value) = 0;
    virtual int digitalGet(uint8_t pin) = 0;
    virtual unsigned long milliseconds() = 0;
};

#endif