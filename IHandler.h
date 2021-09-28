#ifndef IHandler_h
#define IHandler_h

#include "IDevice.h"
#include "IController.h"
#include "Definitions.h"
#include "Diagnostics.h"

class IHandler
{
private:
	short _dep;

public:
	IHandler(short dependentHandlerId = -1) : _dep(dependentHandlerId)
	{
		traceme;
	}

	virtual ~IHandler()
	{
		traceme;
	};

	virtual bool getDependentHandlerResult(bool *results)
	{
		return _dep < 0 ? false : results[_dep];
	}

	virtual bool execute(HANDLER_ARGS) = 0;
};

#endif
