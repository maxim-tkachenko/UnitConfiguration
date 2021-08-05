#include "Button.h"
#include "AVRPlatform.h"

Button::Button(uint8_t pin)
    : platform(new AVRPlatform()),
      _pin(pin)
{
#ifdef CALL_TRACING_ENABLED
    platform->print(__PRETTY_FUNCTION__);
#endif

    init();
}

Button::~Button()
{
#ifdef CALL_TRACING_ENABLED
    platform->print(__PRETTY_FUNCTION__);
#endif

    delete platform;
}

void Button::init()
{
#ifdef CALL_TRACING_ENABLED
    platform->print(__PRETTY_FUNCTION__);
#endif

    platform->pinIn(_pin);
}

bool Button::readState()
{
    return platform->digitalGet(_pin);
}
