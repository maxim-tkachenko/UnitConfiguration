#ifndef Runner_cpp
#define Runner_cpp

#include "AVRPlatform.h"
#include "KitchenConfiguration.cpp"

class Runner
{
private:
    AVRPlatform _platform;
    KitchenConfiguration *_configuretion;

public:
    ~Runner()
    {
        _platform.print(__PRETTY_FUNCTION__);
        delete _configuretion;
    }

    void setup()
    {
        // serial must be initialized in the setup function of arduino project
        _platform.init();
        _platform.print("v0.6");
        _platform.print(__PRETTY_FUNCTION__);

        _configuretion = new KitchenConfiguration();
    }

    void loop()
    {
        // _platform.print(__PRETTY_FUNCTION__);

        for (auto unit : _configuretion->units)
        {
            unit->check();
        }
    }
};

#endif
