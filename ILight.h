#ifndef ILight_h
#define ILight_h

#include "IPlatform.h"
#include "_uint8_t.h"

class ILight
{
private:
    bool _state;

    // if debug
    uint8_t _ledPin = 255;
    inline static bool _initialized = false;

protected:
    IPlatform *pPlatform;
    ILight(bool initialState);
    void log(const char c[]);

public:
    virtual ~ILight();
    void init();
    virtual bool get();
    virtual void set(bool state);
    virtual void switchState();
};

#endif
