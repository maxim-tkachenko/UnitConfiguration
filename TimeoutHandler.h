#ifndef TimeoutHandler_h
#define TimeoutHandler_h

#include "IHandler.h"
#include "PlatformFeatures.h"
#include "Definitions.h"

class TimeoutHandler : public IHandler
{
private:
	unsigned long _latestInterraction = 0;
	unsigned long _timeout;

public:
	TimeoutHandler(short dependentHandlerId = -1, unsigned long timeoutMs = 1800000); // 30 mins
	virtual bool execute(HANDLER_ARGS);
};

#endif
