#ifndef LightUnit_h
#define LightUnit_h

#include "Button.h"
#include "ILight.h"
#include "AVRPlatform.h"

class LightUnit
{
private:
    AVRPlatform platform{};
    Button *_button;
    ILight *_light;

public:
    LightUnit(Button *button, ILight *light);
    ~LightUnit();
    void check();
};

#endif
