#ifndef IHandler_h
#define IHandler_h

#include "IDevice.h"
#include "IController.h"
#include "Definitions.h"
#include "Diagnostics.h"

class IHandler
{
private:
	short _masterHandlerId;

public:
	IHandler(short masterHandlerId = -1) : _masterHandlerId(masterHandlerId)
	{
		traceme;
	}

	virtual ~IHandler()
	{
		traceme;
	};

	virtual bool getMasterHandlerResult(bool *results)
	{
		return _masterHandlerId < 0 ? false : results[_masterHandlerId];
	}

	virtual bool execute(HANDLER_ARGS) = 0;
};

#endif
