#include "IPlatform.h"

#ifndef ILight_h
#define ILight_h

class ILight
{
private:
    bool _state;

    // if debug
    uint8_t _ledPin;
    volatile bool _initialized = false;

protected:
    IPlatform *pPlatform;
    ILight(bool initialState);
    virtual ~ILight();
    void log(const char c[]);

public:
    void init();
    virtual bool get();
    virtual void set(bool state);
    virtual void switchState();
};

#endif
