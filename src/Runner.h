#ifndef Runner_h
#define Runner_h

#include "IConfiguration.h"
#include "Diagnostics.h"

class Runner
{
private:
    IBaseConfiguration *_configuration = nullptr;

    void loopImpl();

public:
    ~Runner();
    void init();
    void setConfig(IBaseConfiguration *configuration);
    void loop();
};

#endif
