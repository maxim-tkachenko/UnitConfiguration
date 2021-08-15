#ifndef WorkUnit_h
#define WorkUnit_h

#include "Button.h"
#include "ILight.h"
#include "Diagnostics.h"

class WorkUnit
{
private:
    Button *_button;
    ILight *_light;

public:
    WorkUnit(Button *button, ILight *light);
    ~WorkUnit();
    void check();
};

#endif
