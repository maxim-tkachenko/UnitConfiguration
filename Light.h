#ifndef Light_h
#define Light_h

#include "ILight.h"

class Light : public ILight
{
private:
  uint8_t _relayPin;

public:
  Light(uint8_t relayPin, bool initialState = false);
  virtual ~Light();

  void init();
  void set(bool state);
};

#endif
