#ifndef IHandler_h
#define IHandler_h

#include "IDevice.h"
#include "IController.h"
#include "Definitions.h"
#include "Diagnostics.h"

class IHandler
{
public:
	virtual ~IHandler()
	{
		traceme;
	};

	virtual bool execute(HANDLER_ARGS) = 0;
};

#endif
