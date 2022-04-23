#ifndef Button_h
#define Button_h

#include "_uint8_t.h"
#include "PlatformFeatures.h"
#include "Diagnostics.h"
#include "IController.h"

class Button : public IController
{
private:
    uint8_t _pin;
    bool _pullup;
    bool _prevState;

protected:
    virtual void init() override;

public:
    Button(uint8_t pin, bool pullup, uint8_t id = 0);
    Button(uint8_t pin, uint8_t id = 0);
    virtual ~Button();
    virtual bool readState() override;
    virtual StateChangedResult stateIsChanged() override;
};

#endif
