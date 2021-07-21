#ifndef Runner_h
#define Runner_h

#include "AVRPlatform.h"
#include "IConfiguration.h"

class Runner
{
private:
    AVRPlatform _platform;
    IBaseConfiguration *_configuration;

    void loopImpl();

public:
    ~Runner();
    void setup(IBaseConfiguration *configuration);
    void loop();
};

#endif
