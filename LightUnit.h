#ifndef LightUnit_h
#define LightUnit_h

#include "Button.h"
#include "ILight.h"

class LightUnit
{
private:
    Button *_button;
    ILight *_light;

public:
    LightUnit(Button *button, ILight *light);
    ~LightUnit();
    void check();
};

#endif
