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
#ifdef CALL_TRACING_ENABLED
    _platform.print("v0.8");
    _platform.print(__PRETTY_FUNCTION__);
#endif

    _configuration = configuration;
}

void Runner::loop()
{
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