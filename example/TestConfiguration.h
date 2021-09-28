#ifndef TestConfiguration_h
#define TestConfiguration_h

#include <UnitConfiguration.h>

#define BASIC_CONFIG

class TestConfiguration : public IConfiguration<1>
{
public:
    TestConfiguration()
    {
#ifdef BASIC_CONFIG
        // Setup primitive devices which can be controlled via relay and button, just specify data pins:
        add(new WorkUnit(new GenericDevice(2), new PushButtonDebounced(3)));
#endif
    }
};

#endif
