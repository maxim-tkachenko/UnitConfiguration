#include "PlatformFeatures.h"

#ifdef __AVR
#include "Arduino.h"
#else
#include <iostream>
using namespace std;
#endif

void PlatformFeatures::init()
{
#ifdef __AVR
    Serial.begin(9600);
    while (!Serial)
        ;
#endif

#ifdef TRACE_ENABLED
    println("v0.9");
    print("TRACE: ");
    println(__PRETTY_FUNCTION__);
#endif

#ifdef LED_PIN_ENABLED
    pinOut(ledPin());
#endif
}

void PlatformFeatures::print(const char c[])
{
#ifdef __AVR
    Serial.print(c);
#else
    cout << c;
#endif
}

void PlatformFeatures::println(const char c[])
{
#ifdef __AVR
    Serial.println(c);
#else
    cout << c << endl;
#endif
}

int PlatformFeatures::ledPin()
{
#ifdef __AVR
    return LED_BUILTIN;
#else
    return -1;
#endif
}

void PlatformFeatures::pinIn(uint8_t pin)
{
#ifdef __AVR
    pinMode(pin, INPUT);
#else
    cout << "pin input mode set for " << pin << endl;
#endif
}

void PlatformFeatures::pinOut(uint8_t pin)
{
#ifdef __AVR
    pinMode(pin, OUTPUT);
#else
    cout << "pin output mode set for " << pin << endl;
#endif
}

void PlatformFeatures::digitalSet(uint8_t pin, uint8_t value)
{
#ifdef __AVR
    digitalWrite(pin, value);
#else
    cout << value << " value set for " << pin << endl;
#endif
}

int PlatformFeatures::digitalGet(uint8_t pin)
{
#ifdef __AVR
    return digitalRead(pin);
#else
    (void)pin; // suppress warning
    return 1;
#endif
}

unsigned long PlatformFeatures::milliseconds()
{
#ifdef __AVR
    return millis();
#else
    return 1234567;
#endif
}