#include "_uint8_t.h"
#include "IPlatform.h"

#ifndef Button_h
#define Button_h

class Button
{
protected:
    uint8_t _buttonPin;
    IPlatform *pPlatform;

    void init();

public:
    Button(uint8_t pin);
    virtual bool readState();
};

#endif
