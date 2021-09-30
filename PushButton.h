#ifndef PushButton_h
#define PushButton_h

#include "_uint8_t.h"
#include "PlatformFeatures.h"
#include "Diagnostics.h"
#include "IController.h"

class PushButton : public IController
{
private:
    uint8_t _pin;
    bool _prevState;

protected:
    virtual void init() override;

public:
    PushButton(uint8_t pin, uint8_t id = 0);
    virtual ~PushButton();
    virtual bool readState() override;
    virtual bool stateIsChanged() override;
};

#endif
