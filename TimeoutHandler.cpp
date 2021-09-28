#include "TimeoutHandler.h"

TimeoutHandler::TimeoutHandler(short dependentHandlerId, unsigned long timeoutMs)
    : IHandler(dependentHandlerId), _timeout(timeoutMs)
{
    traceme;
}

bool TimeoutHandler::execute(HANDLER_ARGS)
{
    (void)controllers;
    (void)controllersCount;

    auto interracted = getDependentHandlerResult(results);
    auto current = PlatformFeatures::milliseconds();

    if (interracted)
    {
        _latestInterraction = current;

        return false;
    }

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