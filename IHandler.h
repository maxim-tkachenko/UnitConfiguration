#ifndef IHandler_h
#define IHandler_h

#include "IDevice.h"
#include "IController.h"

class IHandler
{
public:
	virtual ~IHandler() = default;
	virtual bool Execute(
		IDevice *device,
		IController **controllers,
		uint8_t size) = 0;
};

#endif
