#ifndef WorkUnit_h
#define WorkUnit_h

#include "Button.h"
#include "ILight.h"
#include "Diagnostics.h"

class WorkUnit
{
private:
    uint8_t _size;
    Button **_controllers;
    ILight *_light;

public:
    WorkUnit(ILight *light, Button *button);
    WorkUnit(ILight *light, Button **button, uint8_t size);
    ~WorkUnit();
    void check();
};

#endif
