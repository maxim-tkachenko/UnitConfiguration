#include "IPlatform.h"

#ifndef AVRPlatform_h
#define AVRPlatform_h

class AVRPlatform : public IPlatform
{
public:
    void print(const char c[]);
};

#endif