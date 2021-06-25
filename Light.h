#include "ILight.h"

#ifndef Light_h
#define Light_h

class Light: public ILight
{
    //private:
    //    int relayPin;

  public:
    int relayPin;
    Light(
      int buttonPin,
      int relayPin,
      bool initialState);

    void init();
    void set(bool state);
};

#endif
