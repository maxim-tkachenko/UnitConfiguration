#include "ILight.h"

#ifndef Light_h
#define Light_h

class Light : public ILight
{
protected:
  int relayPin;

public:
  Light(int relayPin, bool initialState);

  void init();
  void set(bool state);
};

#endif
