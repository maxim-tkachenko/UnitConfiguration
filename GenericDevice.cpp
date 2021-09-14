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

  if (_turnConfig == nullptr)
  {
    auto genericDeviceTurnConfig = new GenericDeviceTurnConfig();
    genericDeviceTurnConfig->init(this);

    _turnConfig = genericDeviceTurnConfig;
  }
  else
  {
    config->init(this);
  }

  if (animation != nullptr)
  {
    animation->init(this);
  }

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

// void GenericDevice::setImpl(bool state)
// {
//   traceme;

//   PlatformFeatures::digitalSet(_dataPin, state);
// }

uint8_t GenericDevice::getPin()
{
  return _dataPin;
}
