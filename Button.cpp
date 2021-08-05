#include "Button.h"
#include "AVRPlatform.h"

Button::Button(uint8_t pin)
    : pPlatform(new AVRPlatform()),
      _pin(pin)
{
#ifdef CALL_TRACING_ENABLED
    pPlatform->print(__PRETTY_FUNCTION__);
#endif

    init();
}

Button::~Button()
{
#ifdef CALL_TRACING_ENABLED
    pPlatform->print(__PRETTY_FUNCTION__);
#endif

    delete pPlatform;
}

void Button::init()
{
#ifdef CALL_TRACING_ENABLED
    pPlatform->print(__PRETTY_FUNCTION__);
#endif

    pPlatform->pinIn(_pin);
}

bool Button::readState()
{
    return pPlatform->digitalGet(_pin);
}
