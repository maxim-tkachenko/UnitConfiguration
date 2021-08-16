#ifndef Light_h
#define Light_h

#include "IDevice.h"
#include "Diagnostics.h"

class GenericDevice : public IDevice
{
private:
  uint8_t _dataPin;

public:
  GenericDevice(uint8_t dataPin, bool initialState = false);
  virtual ~GenericDevice();

  void init();
  void set(bool state);
};

#endif
