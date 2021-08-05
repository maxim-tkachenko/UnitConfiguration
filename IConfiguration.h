#ifndef IConfiguration_h
#define IConfiguration_h

#include "crossplatform_size_t.h"
#include "LightUnit.h"
#ifdef CALL_TRACING_ENABLED
#include "AVRPlatform.h"
#endif

class IBaseConfiguration
{
public:
    virtual LightUnit *next() = 0;
    virtual void reset() = 0;
    virtual void add(LightUnit *unit) = 0;
    virtual ~IBaseConfiguration()
    {
    }
};

template <size_t SIZE>
class IConfiguration : public IBaseConfiguration
{
private:
    uint8_t _index = 0;
    LightUnit *_units[SIZE];

#ifdef CALL_TRACING_ENABLED
protected:
    AVRPlatform platform{};
#endif

public:
    LightUnit *next()
    {
        if (_index == SIZE)
        {
            return nullptr;
        }

        return _units[_index++];
    }

    void reset()
    {
        _index = 0;
    }

    void add(LightUnit *unit)
    {
        _units[_index++] = unit;

#ifdef CALL_TRACING_ENABLED
        platform.print(__PRETTY_FUNCTION__);
#endif
    }

    virtual ~IConfiguration()
    {
#ifdef CALL_TRACING_ENABLED
        platform.print(__PRETTY_FUNCTION__);
#endif

        for (auto &unit : _units)
        {
            delete unit;
        }
    }
};

#endif
