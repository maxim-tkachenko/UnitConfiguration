#ifndef IController_h
#define IController_h

#include "IPlatform.h"
#include "Diagnostics.h"

class IController
{
protected:
	IPlatform *platform;

	virtual void init() = 0;

public:
	IController();
	virtual ~IController();
	virtual bool readState() = 0;
};

#endif
