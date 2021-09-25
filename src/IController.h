#ifndef IController_h
#define IController_h

#include "Diagnostics.h"

class IController
{
protected:
	virtual void init() = 0;

public:
	IController();
	virtual ~IController();
	virtual bool readState() = 0;
};

#endif
