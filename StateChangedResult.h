#ifndef StateChangedResult_h
#define StateChangedResult_h

#include "_uint8_t.h"

struct StateChangedResult
{
public:
    bool isChanged;
    bool newState;
    uint8_t newStateCode;

    StateChangedResult(bool isChanged, bool newState, uint8_t newStateCode = 0)
        : isChanged(isChanged), newState(newState), newStateCode(newStateCode)
    {
    }
};

#endif
