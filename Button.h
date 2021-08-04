#ifndef Button_h
#define Button_h

#include "_uint8_t.h"
#include "IPlatform.h"

class Button
{
private:
    uint8_t _pin;

protected:
    IPlatform *pPlatform;

    void init();

public:
    Button(uint8_t pin);
    virtual ~Button();
    virtual bool readState();
};

#endif
