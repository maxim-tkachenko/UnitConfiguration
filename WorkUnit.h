#ifndef WorkUnit_h
#define WorkUnit_h

#include "Button.h"
#include "IDevice.h"
#include "Diagnostics.h"

class WorkUnit
{
private:
    uint8_t _size;
    Button **_controllers;
    IDevice *_device;

public:
    WorkUnit(IDevice *device, Button *button);
    WorkUnit(IDevice *device, Button **button, uint8_t size);
    ~WorkUnit();
    void check();
};

#endif
