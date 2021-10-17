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

        for (short ci = 0; ci < controllersCount; ci++)
        {
            auto stateChanges = controllers[ci]->stateIsChanged();
            if (stateChanges.isChanged)
            {
                if (ci == DOOR_REED_SWITCH_ID)
                {
                    PlatformFeatures::print("reed switch triggerred to ");

                    if (stateChanges.newState)
                    {
                        PlatformFeatures::print("on");
                        if (devices[0]->get())
                        {
                            // do nothing if door is opened but light is already on
                            PlatformFeatures::println(" but ignored");
                            return false;
                        }
                        else
                        {
                            PlatformFeatures::println(" and changed state");
                            for (short di = 0; di < devicesCount; di++)
                            {
                                devices[di]->switchState(true, ci);
                            }

                            return true;
                        }
                    }

                    PlatformFeatures::println("off");

                    // do nothing if door is closed
                    return false;
                }

                PlatformFeatures::println("controller triggerred");
                for (short di = 0; di < devicesCount; di++)
                {
                    devices[di]->switchState(true, ci);
                }

                return true;
            }
        }

        return false;
    }
};

#endif
