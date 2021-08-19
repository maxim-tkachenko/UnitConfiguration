#include "IDevice.h"
#include "AVRPlatform.h"

bool IDevice::_initialized = false;

IDevice::IDevice(bool initialState)
    : platform(new AVRPlatform()),
      _state(initialState)
{
  traceme;

  _ledPin = platform->ledPin();
}

IDevice::~IDevice()
{
  traceme;

  delete platform;
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

  if (!_initialized)
  {
    platform->pinOut(_ledPin);
    _initialized = true;
  }

  platform->digitalSet(_ledPin, state);

  _state = state;
}

void IDevice::switchState()
{
  traceme;

  set(!_state);
}
