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

void IDevice::set(bool state, bool animate, uint8_t requestorId)
{
  traceme;

#ifdef LED_PIN_ENABLED
  PlatformFeatures::digitalSet(PlatformFeatures::ledPin(), state);
#endif

  if (animate)
  {
    if (_turnAnimation == nullptr)
    {
      turn(state, requestorId);
    }
    else
    {
      bool handled = _turnAnimation->execute(state, requestorId);
      if (!handled)
      {
        turn(state, requestorId);
      }
    }
  }
  else
  {
    turn(state, requestorId);
  }

  _state = state;
}

void IDevice::turn(bool state, uint8_t requestorId)
{
  bool handled = _turnConfig->execute(state, requestorId);
  if (!handled)
  {
    // throw;
  }
}

void IDevice::switchState(bool animate, uint8_t requestorId)
{
  traceme;

  set(!_state, animate, requestorId);
}
