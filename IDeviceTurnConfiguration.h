#ifndef IDeviceTurnConfiguration_h
#define IDeviceTurnConfiguration_h

#include "IDevice.h"

class IDeviceBaseTurnConfiguration
{
public:
	virtual bool on() = 0;
	virtual bool off() = 0;

	bool execute(bool state)
	{
		return state ? on() : off();
	}

	virtual ~IDeviceBaseTurnConfiguration()
	{
		traceme;
	}
};

template <class TDevice>
class IDeviceTurnConfiguration : public IDeviceBaseTurnConfiguration
{
protected:
	TDevice *_device = nullptr;

public:
	void init(TDevice *device)
	{
		traceme;

		_device = device;
	}
};

#endif
