#include "Button.h"
#include "AVRPlatform.h"

Button::Button(uint8_t pin)
{
    pPlatform = new AVRPlatform();
#ifdef CALL_TRACING_ENABLED
    pPlatform->print(__PRETTY_FUNCTION__);
#endif

    _buttonPin = pin;
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

    pPlatform->pinIn(_buttonPin);
}

bool Button::readState()
{
    return pPlatform->digitalGet(_buttonPin);
}
