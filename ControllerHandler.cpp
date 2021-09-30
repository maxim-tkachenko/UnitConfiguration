#include "ControllerHandler.h"

// ControllerHandler::ControllerHandler()
// {
// }

// ControllerHandler::~ControllerHandler()
// {
// }

bool ControllerHandler::execute(HANDLER_ARGS)
{
    (void)results;

    for (uint8_t ci = 0; ci < controllersCount; ci++)
    {
        if (controllers[ci]->stateIsChanged())
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