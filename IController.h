#ifndef IController_h
#define IController_h

#include "_uint8_t.h"
#include "Diagnostics.h"

class ControllerChangedResult
{
public:
	bool isChanged;
	bool newState;

	ControllerChangedResult(bool _isChanged, bool _newState)
		: isChanged(_isChanged), newState(_newState)
	{
	}
};

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
	virtual bool stateIsChanged() = 0;
	virtual ControllerChangedResult stateIsChanged2() = 0;
	uint8_t getId();
};

#endif
