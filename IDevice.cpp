#include "IDevice.h"

bool IDevice::_initialized = false;

IDevice::IDevice(bool initialState)
    : _state(initialState)
{
  traceme;

  _ledPin = AVRPlatform::ledPin();
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

  if (!_initialized)
  {
    AVRPlatform::pinOut(_ledPin);
    _initialized = true;
  }

  AVRPlatform::digitalSet(_ledPin, state);

  _state = state;
}

void IDevice::switchState()
{
  traceme;

  set(!_state);
}
