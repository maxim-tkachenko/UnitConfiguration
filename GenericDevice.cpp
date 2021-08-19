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

  platform->pinOut(_dataPin);
  IDevice::init();
}

void GenericDevice::set(bool state)
{
  traceme;

  platform->digitalSet(_dataPin, state);
  IDevice::set(state);
}