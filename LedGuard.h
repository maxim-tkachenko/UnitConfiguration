#ifndef LedGuard_h
#define LedGuard_h

#include "IHandler.h"
#include "PlatformFeatures.h"
#include "Definitions.h"

// temp software led workaround to "prevent" led interferences.
class LedGuard : public IHandler
{
private:
    short _deviceIndex; // TODO: nice to have for each handler.
    unsigned long _timeout;
    unsigned long _latestInterraction = 0;

public:
    LedGuard(short masterHandlerId = -1, short deviceIndex = -1, unsigned long timeoutMs = 300000) // 5 mins
        : IHandler(masterHandlerId), _deviceIndex(deviceIndex), _timeout(timeoutMs)
    {
        traceme;
    }

    bool execute(HANDLER_ARGS)
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
            PlatformFeatures::println("re-filled");

            if (_deviceIndex == -1)
            {
                for (uint8_t di = 0; di < devicesCount; di++)
                {
                    devices[di]->set(devices[di]->get());
                }
            }
            else
            {
                devices[_deviceIndex]->set(devices[_deviceIndex]->get());
            }

            _latestInterraction = current;

            return true;
        }

        return false;
    }
};

#endif
