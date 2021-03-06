#ifndef GenericDeviceTurnConfig_h
#define GenericDeviceTurnConfig_h

#include "GenericDevice.h"

class GenericDeviceTurnConfig : public IDeviceTurnConfiguration<GenericDevice>
{
private:
	void set(bool state)
	{
		PlatformFeatures::digitalSet(_device->getPin(), state);
	}

public:
	bool on(uint8_t requestorId) override
	{
		traceme;
		(void)requestorId;

		set(true);
		return true;
	}

	bool off(uint8_t requestorId) override
	{
		traceme;
		(void)requestorId;

		set(false);
		return true;
	}
};

#endif
