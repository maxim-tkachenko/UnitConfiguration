#ifndef Runner_h
#define Runner_h

#ifdef CALL_TRACING_ENABLED
#include "AVRPlatform.h"
#endif
#include "IConfiguration.h"

class Runner
{
private:
#ifdef CALL_TRACING_ENABLED
    AVRPlatform _platform{};
#endif
    IBaseConfiguration *_configuration = nullptr;

    void loopImpl();

public:
    ~Runner();
    void setup(IBaseConfiguration *configuration);
    void loop();
};

#endif
