#ifndef IPlatform_h
#define IPlatform_h

class IPlatform
{
public:
    // virtual ~IPlatform();
    virtual void print(const char c[]) = 0;
    virtual int ledPin() = 0;
};

#endif
