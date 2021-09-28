#include "ControllerHandler.h"

// ControllerHandler::ControllerHandler()
// {
// }

// ControllerHandler::~ControllerHandler()
// {
// }

bool ControllerHandler::execute(WORKUNIT_ARGS)
{
    for (uint8_t ci = 0; ci < controllersCount; ci++)
    {
        if (controllers[ci]->readState())
        {
            PlatformFeatures::println("controller triggerred");
            for (uint8_t di = 0; di < devicesCount; di++)
            {
                devices[di]->switchState(true, controllers[ci]->getId());
            }

            return true;
        }
    }

    return false;
}