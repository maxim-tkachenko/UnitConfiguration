#include "Button.h"
#include "ILight.h"

#ifndef LightUnit_h
#define LightUnit_h

class LightUnit
{
private:
    Button *_button;
    ILight *_light;

    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 1000;

public:
    LightUnit(Button &button, ILight &light);
    ~LightUnit();
    void check();
};

#endif
