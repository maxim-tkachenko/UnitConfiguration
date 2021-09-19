#ifndef IDeviceTurnConfiguration_h
#define IDeviceTurnConfiguration_h

#include "IDevice.h"

class IDeviceBaseTurnConfiguration
{
public:
	virtual bool on(uint8_t requestorId) = 0;
	virtual bool off(uint8_t requestorId) = 0;

	bool execute(bool state, uint8_t requestorId = 0)
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
