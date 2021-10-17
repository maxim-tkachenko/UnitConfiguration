#ifndef IDeviceTurnConfiguration_h
#define IDeviceTurnConfiguration_h

#include "IDevice.h"

class IDeviceBaseTurnConfiguration
{
public:
	virtual bool on(short requestorId) = 0;
	virtual bool off(short requestorId) = 0;

	bool execute(bool state, short requestorId = 0)
	{
		return state ? on(requestorId) : off(requestorId);
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
