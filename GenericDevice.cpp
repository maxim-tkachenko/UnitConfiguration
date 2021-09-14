#include "GenericDevice.h"

GenericDevice::GenericDevice(
    uint8_t dataPin,
    IDeviceTurnConfiguration<GenericDevice> *config,
    IDeviceTurnConfiguration<GenericDevice> *animation,
    bool initialState)
    : IDevice(
          // config == nullptr ? new GenericDeviceTurnConfig() : config,
          config,
          animation,
          initialState),
      _dataPin(dataPin)
{
  traceme;

  init();

  // if (config == nullptr)
  // {
  //   // setDefaultTurnConfig();
  //   _turnConfig = new GenericDeviceTurnConfig();
  // }

  if (config != nullptr)
  {
    config->init(this);
  }

  if (animation != nullptr)
  {
    animation->init(this);
  }
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
