#ifndef BathroomControllerHandler_h
#define BathroomControllerHandler_h

#include "IHandler.h"
#include "Definitions.h"

#define WALL_SWITCH_ID 55
#define DOOR_REED_SWITCH_ID 56

class BathroomControllerHandler : public IHandler
{
public:
    bool BathroomControllerHandler::execute(HANDLER_ARGS)
    {
        (void)results;

        for (uint8_t ci = 0; ci < controllersCount; ci++)
        {
            auto stateChanges = controllers[ci]->stateIsChanged();
            if (stateChanges.isChanged)
            {
                if (controllers[ci]->getId() == DOOR_REED_SWITCH_ID)
                {
                    PlatformFeatures::print("reed switch triggerred to ");

                    if (stateChanges.newState &&
                        !devices[0]->get())
                    {
                        PlatformFeatures::println("on");

                        for (uint8_t di = 0; di < devicesCount; di++)
                        {
                            devices[di]->switchState(true, controllers[ci]->getId());
                        }
                    }

                    PlatformFeatures::println("off");

                    // do nothing if door is closed and light already on
                    return false;
                }

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
};

#endif
