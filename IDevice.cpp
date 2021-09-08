#include "IDevice.h"

IDevice::IDevice(bool initialState)
    : _state(initialState)
{
  traceme;
}

IDevice::~IDevice()
{
  traceme;
}

void IDevice::init()
{
  traceme;

  set(_state);
}

bool IDevice::get()
{
  traceme;

  return _state;
}

void IDevice::set(bool state, bool animate)
{
  traceme;

#ifdef LED_PIN_ENABLED
  PlatformFeatures::digitalSet(PlatformFeatures::ledPin(), state);
#endif

  if (animate)
  {
    if (_turnAnimation == nullptr)
    {
      setImpl(state);
    }

    bool handled = _turnAnimation->Execute(state);
    if (!handled)
    {
      setImpl(state);
    }
  }
  else
  {
    setImpl(state);
  }

  _state = state;
}

void IDevice::switchState(bool animate)
{
  traceme;

  set(!_state, animate);
}
