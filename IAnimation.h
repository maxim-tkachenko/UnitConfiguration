#ifndef IANIMATION_H
#define IANIMATION_H

class IAnimation
{
private:
public:
	IAnimation();
	~IAnimation();
	virtual bool Execute(bool state) = 0;
	// virtual void ExecuteInverse() = 0;
};

#endif