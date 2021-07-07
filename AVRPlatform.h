#include "IPlatform.h"

#ifndef AVRPlatform_h
#define AVRPlatform_h

class AVRPlatform : public IPlatform
{
public:
    // ~AVRPlatform();
    void print(const char c[]);
    int ledPin();
    void pinIn(uint8_t pin);
    void pinOut(uint8_t pin);
};

#endif