#include "Runner.h"

Runner::~Runner()
{
#ifdef CALL_TRACING_ENABLED
    _platform.print(__PRETTY_FUNCTION__);
#endif

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