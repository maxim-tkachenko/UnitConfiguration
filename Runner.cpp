#ifndef Runner_cpp
#define Runner_cpp

#include "AVRPlatform.h"
#include "IConfiguration.h"

class Runner
{
private:
    AVRPlatform _platform;
    IBaseConfiguration *_configuration;

    void loopImpl()
    {
        auto next = _configuration->next();
        if (next == nullptr)
        {
            return;
        }

        next->check();
        loopImpl();
    }

public:
    ~Runner()
    {
        _platform.print(__PRETTY_FUNCTION__);
        delete _configuration;
    }

    void setup(IBaseConfiguration *configuration)
    {
        _platform.print("v0.6");
        _platform.print(__PRETTY_FUNCTION__);

        _configuration = configuration;
    }

    void loop()
    {
        // _platform.print(__PRETTY_FUNCTION__);

        _configuration->reset();
        loopImpl();
    }
};

#endif
