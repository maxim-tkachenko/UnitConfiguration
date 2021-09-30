#include "TimeoutHandler.h"

TimeoutHandler::TimeoutHandler(short masterHandlerId, unsigned long timeoutMs)
    : IHandler(masterHandlerId), _timeout(timeoutMs)
{
    traceme;
}

bool TimeoutHandler::execute(HANDLER_ARGS)
{
    (void)controllers;
    (void)controllersCount;

    auto interracted = getMasterHandlerResult(results);
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