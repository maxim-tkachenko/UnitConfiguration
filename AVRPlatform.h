#include "IPlatform.h"

#ifndef AVRPlatform_h
#define AVRPlatform_h

class AVRPlatform : public IPlatform
{
public:
    // ~AVRPlatform();
    void print(const char c[]);
    int ledPin();
};

#endif