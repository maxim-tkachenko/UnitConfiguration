#include "Runner.h"

Runner::~Runner()
{
    traceme;

    delete _configuration;
}

void Runner::init()
{
    traceme;

    PlatformFeatures::init();
}

void Runner::setConfig(IBaseConfiguration *configuration)
{
    traceme;

    _configuration = configuration;
    PlatformFeatures::println("setup finished");
}

void Runner::loop()
{
    _configuration->resetEnumerator();
    loopImpl();
}

void Runner::loopImpl()
{
    auto next = _configuration->next();
    if (next == nullptr)
    {
        return;
    }

    next->check();
    loopImpl();
}