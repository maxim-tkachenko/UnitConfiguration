#ifndef PushButton_h
#define PushButton_h

#include "_uint8_t.h"
#include "IPlatform.h"
#include "Diagnostics.h"

class PushButton
{
private:
    uint8_t _pin;

protected:
    IPlatform *platform;

    void init();

public:
    PushButton(uint8_t pin);
    virtual ~PushButton();
    virtual bool readState();
};

#endif
