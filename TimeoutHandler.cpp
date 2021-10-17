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
        // treat master's handler interraction as its own
        // since there is some activity has been caught.
        _latestInterraction = current;

        return false;
    }

    if ((current - _latestInterraction) > _timeout)
    {
        PlatformFeatures::print("timeout");

        for (uint8_t di = 0; di < devicesCount; di++)
        {
            if (devices[di]->get())
            {
                devices[di]->set(false);
                PlatformFeatures::print("!");
            }
        }

        PlatformFeatures::println("");
        _latestInterraction = current;

        return true;
    }

    return false;
}