#include "IDevice.h"

IDevice::IDevice(
    IDeviceBaseTurnConfiguration *config,
    IDeviceBaseTurnConfiguration *animation,
    bool initialState)
    : _state(initialState), _turnConfig(config), _turnAnimation(animation)
{
  traceme;
}

IDevice::~IDevice()
{
  traceme;

  if (_turnAnimation != nullptr)
  {
    delete _turnAnimation;
  }

  delete _turnConfig;
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
      turn(state);
    }
    else
    {
      bool handled = _turnAnimation->execute(state);
      if (!handled)
      {
        turn(state);
      }
    }
  }
  else
  {
    turn(state);
  }

  _state = state;
}

void IDevice::turn(bool state)
{
  bool handled = _turnConfig->execute(state);
  if (!handled)
  {
    // throw;
  }
}

void IDevice::switchState(bool animate)
{
  traceme;

  set(!_state, animate);
}
