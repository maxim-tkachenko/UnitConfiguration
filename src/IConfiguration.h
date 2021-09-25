#ifndef IConfiguration_h
#define IConfiguration_h

#include "WorkUnit.h"
#include "Diagnostics.h"

class IBaseConfiguration
{
public:
    virtual WorkUnit *next() = 0;
    virtual void resetEnumerator() = 0;
    virtual void add(WorkUnit *unit) = 0;
    virtual ~IBaseConfiguration()
    {
    }
};

template <uint8_t SIZE>
class IConfiguration : public IBaseConfiguration
{
private:
    uint8_t _index = 0;
    WorkUnit *_units[SIZE]{};

public:
    WorkUnit *next() override
    {
        if (_index == SIZE)
        {
            return nullptr;
        }

        return _units[_index++];
    }

    void resetEnumerator() override
    {
        _index = 0;
    }

    void add(WorkUnit *unit) override
    {
        traceme;

        _units[_index++] = unit;
    }

    virtual ~IConfiguration() override
    {
        traceme;

        for (auto unit : _units)
        {
            delete unit;
        }
    }
};

#endif
