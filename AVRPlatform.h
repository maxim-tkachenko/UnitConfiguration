#ifndef AVRPlatform_h
#define AVRPlatform_h

#include "IPlatform.h"

class AVRPlatform : public IPlatform
{
private:
    inline static bool _initialized = false;

public:
    AVRPlatform();
    virtual ~AVRPlatform();
    void print(const char c[]);
    int ledPin();
    void pinIn(uint8_t pin);
    void pinOut(uint8_t pin);
    void digitalSet(uint8_t pin, uint8_t value);
    int digitalGet(uint8_t pin);
    unsigned long milliseconds();
};

#endif