#include "AVRPlatform.h"

#ifdef __AVR
#include "Arduino.h"
#else
#include <iostream>
using namespace std;
#endif

AVRPlatform::~AVRPlatform()
{
#ifdef PLATFORM_FEATURES_DESTRUCTION_LOG_ENABLED
#ifdef TRACE_ENABLED
    println(__PRETTY_FUNCTION__);
#endif
#endif
}

void AVRPlatform::println(const char c[])
{
#ifdef __AVR
    Serial.println(c);
#else
    cout << c << endl;
#endif
}

int AVRPlatform::ledPin()
{
#ifdef __AVR
    return LED_BUILTIN;
#else
    return -1;
#endif
}

void AVRPlatform::pinIn(uint8_t pin)
{
#ifdef __AVR
    pinMode(pin, INPUT);
#else
    cout << "pin input mode set for " << pin << endl;
#endif
}

void AVRPlatform::pinOut(uint8_t pin)
{
#ifdef __AVR
    pinMode(pin, OUTPUT);
#else
    cout << "pin output mode set for " << pin << endl;
#endif
}

void AVRPlatform::digitalSet(uint8_t pin, uint8_t value)
{
#ifdef __AVR
    digitalWrite(pin, value);
#else
    cout << value << "value set for " << pin << endl;
#endif
}

int AVRPlatform::digitalGet(uint8_t pin)
{
#ifdef __AVR
    return digitalRead(pin);
#else
    return 1;
#endif
}

unsigned long AVRPlatform::milliseconds()
{
#ifdef __AVR
    return millis();
#else
    return 1234567;
#endif
}