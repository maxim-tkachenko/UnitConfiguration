#ifndef Light_h
#define Light_h

#include "IDevice.h"
#include "Diagnostics.h"

class Light : public IDevice
{
private:
  uint8_t _dataPin;

public:
  Light(uint8_t dataPin, bool initialState = false);
  virtual ~Light();

  void init();
  void set(bool state);
};

#endif
