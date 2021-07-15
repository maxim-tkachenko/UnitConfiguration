#ifndef IConfiguration_h
#define IConfiguration_h

#include "LightUnit.h"

class IBaseConfiguration
{
public:
    virtual LightUnit *next() = 0;
    virtual void reset() = 0;
    virtual ~IBaseConfiguration()
    {
    }
};

template <size_t SIZE>
class IConfiguration : public IBaseConfiguration
{
private:
    int _index;

protected:
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

    virtual ~IConfiguration()
    {
        for (auto &unit : units)
        {
            delete unit;
        }
    }
};

#endif
