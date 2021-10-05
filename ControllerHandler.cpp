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
        auto stateIsChanged = controllers[ci]->stateIsChanged2();
        // if (controllers[ci]->stateIsChanged())
        if (stateIsChanged.isChanged)
        {
            // auto newState = controllers[ci]->readState();
            PlatformFeatures::println("controller triggerred");
            for (uint8_t di = 0; di < devicesCount; di++)
            {
                // devices[di]->switchState(true, controllers[ci]->getId());
                devices[di]->set(stateIsChanged.newState, true, controllers[ci]->getId());
            }

            return true;
        }
    }

    return false;
}