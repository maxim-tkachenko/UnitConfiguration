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
        AVRPlatform::println("btn pressed");
        _latestInterraction = AVRPlatform::milliseconds();

        return false;
    }

    auto current = AVRPlatform::milliseconds();
    if ((current - _latestInterraction) > _timeout && device->get())
    {
        AVRPlatform::println("timeout");
        device->set(false);
        _latestInterraction = current;

        return true;
    }

    return false;
}