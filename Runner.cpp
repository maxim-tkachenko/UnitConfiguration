#include "Runner.h"

Runner::~Runner()
{
    _platform.print(__PRETTY_FUNCTION__);
    delete _configuration;
}

void Runner::setup(IBaseConfiguration *configuration)
{
    _platform.print("v0.7");
    _platform.print(__PRETTY_FUNCTION__);

    _configuration = configuration;
}

void Runner::loop()
{
    // _platform.print(__PRETTY_FUNCTION__);

    _configuration->reset();
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