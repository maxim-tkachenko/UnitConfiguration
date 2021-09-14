#include "GenericDevice.h"
#include "GenericDeviceTurnConfig.h"

GenericDevice::GenericDevice(
    uint8_t dataPin,
    IDeviceTurnConfiguration<GenericDevice> *config,
    IDeviceTurnConfiguration<GenericDevice> *animation,
    bool initialState)
    : IDevice(config, animation, initialState),
      _dataPin(dataPin)
{
  traceme;

  initConfigs<GenericDevice, GenericDeviceTurnConfig>(config, animation, this);
  init();
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

uint8_t GenericDevice::getPin()
{
  return _dataPin;
}
