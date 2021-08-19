#include "IDevice.h"

bool IDevice::_initialized = false;

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

void IDevice::set(bool state)
{
  traceme;

#ifdef LED_PIN_ENABLED
  PlatformFeatures::digitalSet(PlatformFeatures::ledPin(), state);
#endif

  _state = state;
}

void IDevice::switchState()
{
  traceme;

  set(!_state);
}
