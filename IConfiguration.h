#ifndef IConfiguration_h
#define IConfiguration_h

#include "crossplatform_size_t.h"
#include "LightUnit.h"
#include "Diagnostics.h"

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
        traceme;

        _units[_index++] = unit;
    }

    virtual ~IConfiguration()
    {
        traceme;

        for (auto &unit : _units)
        {
            delete unit;
        }
    }
};

#endif
