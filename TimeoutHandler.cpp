#include "TimeoutHandler.h"

TimeoutHandler::TimeoutHandler(unsigned long timeoutMs)
    : _timeout(timeoutMs)
{
    traceme;
}

bool TimeoutHandler::Execute(WORKUNIT_ARGS)
{
    auto interracted = ControllerHandler::Execute(device, controllers, size);
    if (interracted)
    {
        platform.println("btn pressed");
        _latestInterraction = platform.milliseconds();

        return false;
    }

    auto current = platform.milliseconds();
    if ((current - _latestInterraction) > _timeout && device->get())
    {
        platform.println("timeout");
        device->set(false);
        _latestInterraction = current;

        return true;
    }

    return false;
}