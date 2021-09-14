#ifndef GenericDevice_h
#define GenericDevice_h

#include "IDevice.h"
// #include "GenericDeviceTurnConfig.h"
#include "PlatformFeatures.h"
#include "Diagnostics.h"

class GenericDevice : public IDevice
{
private:
  uint8_t _dataPin;

protected:
  // void setImpl(bool state) override;

public:
  GenericDevice(
      uint8_t dataPin,
      IDeviceTurnConfiguration<GenericDevice> *config = nullptr,
      IDeviceTurnConfiguration<GenericDevice> *animation = nullptr,
      bool initialState = false);
  virtual ~GenericDevice();

  void init();
  uint8_t getPin();
};

#endif
