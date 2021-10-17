#ifndef IController_h
#define IController_h

#include "StateChangedResult.h"
#include "_uint8_t.h"
#include "Diagnostics.h"

class IController
{
protected:
	virtual void init() = 0;

public:
	virtual ~IController();
	virtual bool readState() = 0;
	virtual StateChangedResult stateIsChanged() = 0;
};

#endif
