#include "PlatformFeatures.h"

#if REAL_BOARD
#include "Arduino.h"
#else
#include <iostream>
using namespace std;
#endif

void PlatformFeatures::init()
{
#if REAL_BOARD
    Serial.begin(115200);
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
#if REAL_BOARD
    Serial.print(c);
#else
    cout << c;
#endif
}

void PlatformFeatures::println(const char c[])
{
#if REAL_BOARD
    Serial.println(c);
#else
    cout << c << endl;
#endif
}

int PlatformFeatures::ledPin()
{
#if REAL_BOARD
    return LED_BUILTIN;
#else
    return -1;
#endif
}

void PlatformFeatures::pinIn(uint8_t pin, bool pullup)
{
#if REAL_BOARD
    pinMode(pin, pullup ? INPUT_PULLUP : INPUT);
#else
    (void)pullup;
    cout << "pin input mode set for " << pin << endl;
#endif
}

void PlatformFeatures::pinOut(uint8_t pin)
{
#if REAL_BOARD
    pinMode(pin, OUTPUT);
#else
    cout << "pin output mode set for " << pin << endl;
#endif
}

void PlatformFeatures::digitalSet(uint8_t pin, uint8_t value)
{
#if REAL_BOARD
    digitalWrite(pin, proxyValue(value));
#else
    cout << value << " value set for " << pin << endl;
#endif
}

int PlatformFeatures::digitalGet(uint8_t pin)
{
#if REAL_BOARD
    return proxyValue(digitalRead(pin));
#else
    (void)pin; // suppress warning
    return 1;
#endif
}

unsigned long PlatformFeatures::milliseconds()
{
#if REAL_BOARD
    return millis();
#else
    return 1234567;
#endif
}

bool PlatformFeatures::proxyValue(bool value)
{
#if defined(ARDUINO_ARCH_ESP8266)
    return !value;
#elif defined(__AVR)
    return value;
#else
#ifdef TRACE_ENABLED
    println("unrecognized platform");
#endif
    return value;
#endif
}