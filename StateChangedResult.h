#ifndef StateChangedResult_h
#define StateChangedResult_h

#include "_uint8_t.h"

struct StateChangedResult
{
public:
    // TODO: remove these two in favour of newStateCode
    bool isChanged;
    bool newState;

    uint8_t newStateCode;

    bool isClicked()
    {
        return newStateCode != 0;
    }

    StateChangedResult(bool isChanged, bool newState, uint8_t newStateCode = 0)
        : isChanged(isChanged), newState(newState), newStateCode(newStateCode)
    {
    }
};

#endif
