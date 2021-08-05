#ifndef LightUnit_h
#define LightUnit_h

#include "Button.h"
#include "ILight.h"
#ifdef CALL_TRACING_ENABLED
#include "AVRPlatform.h"
#endif

class LightUnit
{
private:
#ifdef CALL_TRACING_ENABLED
    AVRPlatform platform{};
#endif
    Button *_button;
    ILight *_light;

public:
    LightUnit(Button *button, ILight *light);
    ~LightUnit();
    void check();
};

#endif
