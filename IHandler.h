#ifndef IHandler_h
#define IHandler_h

#include "IDevice.h"
#include "IController.h"
#include "AVRPlatform.h"
#include "Diagnostics.h"

class IHandler
{
protected:
	AVRPlatform platform{};

public:
	virtual ~IHandler()
	{
		traceme;
	};

	virtual bool Execute(
		IDevice *device,
		IController **controllers,
		uint8_t size) = 0;
};

#endif
