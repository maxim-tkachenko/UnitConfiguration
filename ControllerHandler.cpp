#include "ControllerHandler.h"

// ControllerHandler::ControllerHandler()
// {
// }

// ControllerHandler::~ControllerHandler()
// {
// }

bool ControllerHandler::Execute(WORKUNIT_ARGS)
{
    bool result = false;
    for (uint8_t i = 0; i < controllersCount; i++)
    {
        if (controllers[i]->readState())
        {
            device->switchState();
            result = true;
        }
    }

    return result;
}