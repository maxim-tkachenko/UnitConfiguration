#ifndef WorkUnit_h
#define WorkUnit_h

#include "PushButton.h"
#include "IDevice.h"
#include "Diagnostics.h"

class WorkUnit
{
private:
    uint8_t _size;
    PushButton **_controllers;
    IDevice *_device;

public:
    WorkUnit(IDevice *device, PushButton *button);
    WorkUnit(IDevice *device, PushButton **button, uint8_t size);
    ~WorkUnit();
    void check();
};

#endif
