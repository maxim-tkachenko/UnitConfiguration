#include "Button.h"
#include "ILight.h"

#ifndef LightUnit_h
#define LightUnit_h

class LightUnit
{
private:
    Button *_button;
    ILight *_light;

public:
    LightUnit(Button &button, ILight &light);
    ~LightUnit();
    void check();
};

#endif
