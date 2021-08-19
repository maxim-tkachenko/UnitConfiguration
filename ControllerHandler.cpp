#include "ControllerHandler.h"

// ControllerHandler::ControllerHandler()
// {
// }

// ControllerHandler::~ControllerHandler()
// {
// }

bool ControllerHandler::Execute(IDevice *device, IController **controllers, uint8_t size)
{
    bool result = false;
    for (uint8_t i = 0; i < size; i++)
    {
        if (controllers[i]->readState())
        {
            device->switchState();
            result = true;
        }
    }

    return result;
}