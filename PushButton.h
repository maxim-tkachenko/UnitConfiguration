#ifndef PushButton_h
#define PushButton_h

#include "_uint8_t.h"
#include "Diagnostics.h"
#include "IController.h"

class PushButton : public IController
{
private:
    uint8_t _pin;

protected:
    virtual void init();

public:
    PushButton(uint8_t pin);
    virtual ~PushButton();
    virtual bool readState();
};

#endif
