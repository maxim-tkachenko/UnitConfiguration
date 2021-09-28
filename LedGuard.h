#ifndef LedGuard_h
#define LedGuard_h

#include "UnitConfiguration.h"

// temp software led workaround to "prevent" led interferences.
class LedGuard : public ControllerHandler
{
private:
    unsigned long _timeout;
    unsigned long _latestInterraction = 0;

public:
    LedGuard(unsigned long timeoutMs = 300000) // 5 mins
        : _timeout(timeoutMs)
    {
        traceme;
    }

    bool execute(HANDLER_ARGS)
    {
        auto interracted = ControllerHandler::execute(HANDLER_ARGS_PASS);
        auto current = PlatformFeatures::milliseconds();

        if (interracted)
        {
            _latestInterraction = current;

            return false;
        }

        if ((current - _latestInterraction) > _timeout)
        {
            PlatformFeatures::println("re-fill");
            // PlatformFeatures::println(device->get());

            for (uint8_t di = 0; di < devicesCount; di++)
            {
                devices[di]->set(devices[di]->get());
            }

            _latestInterraction = current;

            return true;
        }

        return false;
    }
};

#endif
