#ifndef Button_h
#define Button_h

#include "_uint8_t.h"
#include "IPlatform.h"

class Button
{
protected:
    uint8_t _buttonPin;
    IPlatform *pPlatform;

    void init();

public:
    Button(uint8_t pin);
    virtual ~Button();
    virtual bool readState();
};

#endif
