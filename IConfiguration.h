#ifndef IConfiguration_h
#define IConfiguration_h

#include "crossplatform_size_t.h"
#include "LightUnit.h"

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
    LightUnit *units[SIZE];

public:
    LightUnit *next()
    {
        if (_index == SIZE)
        {
            return nullptr;
        }

        return units[_index++];
    }

    void reset()
    {
        _index = 0;
    }

    void add(LightUnit *unit)
    {
        units[_index++] = unit;
    }

    virtual ~IConfiguration()
    {
        for (auto &unit : units)
        {
            delete unit;
        }
    }
};

#endif
