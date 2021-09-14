#ifndef GenericDeviceTurnConfig_h
#define GenericDeviceTurnConfig_h

#include "GenericDevice.h"

// class GenericDevice;

class GenericDeviceTurnConfig : public IDeviceTurnConfiguration<GenericDevice>
{
private:
	void set(bool state)
	{
		PlatformFeatures::digitalSet(_device->getPin(), state);
	}

public:
	bool on() override
	{
		traceme;

		set(true);
		return true;
	}

	bool off() override
	{
		traceme;

		set(false);
		return true;
	}
};

#endif
