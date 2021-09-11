#ifndef IAnimation_h
#define IAnimation_h

#include "IDevice.h"

class IBaseAnimation
{
public:
	virtual bool on() = 0;
	virtual bool off() = 0;
	bool execute(bool state)
	{
		return state ? on() : off();
	}

	// template <class TDevice>
	// void init(TDevice *device)
	// {
	// }
};

template <class TDevice>
class IAnimation : public IBaseAnimation
{
protected:
	TDevice *_device = nullptr;

public:
	// IAnimation(TDevice *device) : _device(device)
	// {
	// 	traceme;
	// }

	void init(TDevice *device)
	{
		traceme;

		_device = device;
	}
};

#endif