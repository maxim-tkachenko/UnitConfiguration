#include "IDevice.h"

IDevice::IDevice(bool initialState)
    : IDevice(nullptr, initialState)
{
  traceme;
}

IDevice::IDevice(IBaseAnimation *animation, bool initialState)
    : _state(initialState), _turnAnimation(animation)
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
    else
    {
      bool handled = _turnAnimation->execute(state);
      if (!handled)
      {
        setImpl(state);
      }
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
