#include "Runner.h"

Runner::~Runner()
{
    traceme;

    delete _configuration;
}

void Runner::setup(IBaseConfiguration *configuration)
{
    traceme;

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