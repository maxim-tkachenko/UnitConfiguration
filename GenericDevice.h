#ifndef GenericDevice_h
#define GenericDevice_h

#include "IDevice.h"
#include "PlatformFeatures.h"
#include "Diagnostics.h"

class GenericDevice : public IDevice
{
private:
  uint8_t _dataPin;

protected:
  void setImpl(bool state) override;

public:
  GenericDevice(uint8_t dataPin, bool initialState = false);
  GenericDevice(uint8_t dataPin, IAnimation<GenericDevice> *animation, bool initialState = false);
  virtual ~GenericDevice();

  void init();
};

#endif
