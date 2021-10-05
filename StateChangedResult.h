#ifndef StateChangedResult_h
#define StateChangedResult_h

struct StateChangedResult
{
public:
    bool isChanged;
    bool newState;

    StateChangedResult(bool isChanged, bool newState)
        : isChanged(isChanged), newState(newState)
    {
    }
};

#endif
