#include "GenericDevice.h"

GenericDevice::GenericDevice(uint8_t dataPin, IBaseAnimation *animation, bool initialState)
    : IDevice(animation, initialState),
      _dataPin(dataPin)
{
  traceme;

  init();
}

GenericDevice::GenericDevice(uint8_t dataPin, bool initialState)
    : GenericDevice(dataPin, nullptr, initialState)
{
  traceme;
}

GenericDevice::~GenericDevice()
{
  traceme;
}

void GenericDevice::init()
{
  traceme;

  PlatformFeatures::pinOut(_dataPin);
  IDevice::init();
}

void GenericDevice::setImpl(bool state)
{
  traceme;

  PlatformFeatures::digitalSet(_dataPin, state);
}
