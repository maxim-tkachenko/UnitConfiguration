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
        auto stateChanges = controllers[ci]->stateIsChanged();
        if (stateChanges.isChanged)
        {
            PlatformFeatures::println("controller triggerred");
            for (uint8_t di = 0; di < devicesCount; di++)
            {
                devices[di]->switchState(true, ci);
            }

            return true;
        }
    }

    return false;
}