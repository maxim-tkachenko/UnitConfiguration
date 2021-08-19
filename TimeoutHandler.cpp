#include "TimeoutHandler.h"

TimeoutHandler::TimeoutHandler(unsigned long timeoutMs)
    : _timeout(timeoutMs)
{
    traceme;
}

bool TimeoutHandler::Execute(WORKUNIT_ARGS)
{
    auto interracted = ControllerHandler::Execute(device, controllers, controllersCount);
    if (interracted)
    {
        PlatformFeatures::println("btn pressed");
        _latestInterraction = PlatformFeatures::milliseconds();

        return false;
    }

    auto current = PlatformFeatures::milliseconds();
    if ((current - _latestInterraction) > _timeout && device->get())
    {
        PlatformFeatures::println("timeout");
        device->set(false);
        _latestInterraction = current;

        return true;
    }

    return false;
}