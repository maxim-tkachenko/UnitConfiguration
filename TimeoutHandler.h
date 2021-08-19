#ifndef TimeoutHandler_h
#define TimeoutHandler_h

#include "ControllerHandler.h"
#include "AVRPlatform.h"
#include "Definitions.h"

class TimeoutHandler : public ControllerHandler
{
private:
	unsigned long _latestInterraction = 0;
	unsigned long _timeout;

public:
	TimeoutHandler(unsigned long timeoutMs = 1800000); // 30 mins
	virtual bool Execute(WORKUNIT_ARGS);
};

#endif
