#include "TimeoutHandler.h"

TimeoutHandler::TimeoutHandler(unsigned long timeoutMs)
    : _timeout(timeoutMs)
{
    traceme;
}

bool TimeoutHandler::execute(WORKUNIT_ARGS)
{
    auto interracted = ControllerHandler::execute(devices, devicesCount, controllers, controllersCount);
    if (interracted)
    {
        _latestInterraction = PlatformFeatures::milliseconds();

        return false;
    }

    auto current = PlatformFeatures::milliseconds();
    if ((current - _latestInterraction) > _timeout)
    {
        for (uint8_t di = 0; di < devicesCount; di++)
        {
            if (devices[di]->get())
            {
                continue;
            }
        }

        PlatformFeatures::println("timeout");

        for (uint8_t di = 0; di < devicesCount; di++)
        {
            devices[di]->set(false);
        }

        _latestInterraction = current;

        return true;
    }

    return false;
}