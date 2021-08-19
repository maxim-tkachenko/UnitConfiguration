#ifndef IProcessor_h
#define IProcessor_h

#include "IDevice.h"
#include "IController.h"

class IProcessor
{
public:
	virtual ~IProcessor() = default;
	virtual bool Execute(
		IDevice *device,
		IController **controllers,
		uint8_t size) = 0;
};

#endif
