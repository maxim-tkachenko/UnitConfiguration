#ifndef IController_h
#define IController_h

#include "_uint8_t.h"
#include "Diagnostics.h"

class IController
{
private:
	uint8_t _id;

protected:
	virtual void init() = 0;

public:
	IController(uint8_t id = 0);
	virtual ~IController();
	virtual bool readState() = 0;
	uint8_t getId();
};

#endif
