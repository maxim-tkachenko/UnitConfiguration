#include "GenericDevice.h"

GenericDevice::GenericDevice(uint8_t dataPin, bool initialState)
    : IDevice(initialState),
      _dataPin(dataPin)
{
  traceme;

  init();
}

GenericDevice::~GenericDevice()
{
  traceme;
}

void GenericDevice::init()
{
  traceme;

  AVRPlatform::pinOut(_dataPin);
  IDevice::init();
}

void GenericDevice::set(bool state)
{
  traceme;

  AVRPlatform::digitalSet(_dataPin, state);
  IDevice::set(state);
}
