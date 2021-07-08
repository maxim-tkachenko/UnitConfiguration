#include "AVRPlatform.h"
#include "Arduino.h"

void AVRPlatform::print(const char c[])
{
    //Serial.println(__PRETTY_FUNCTION__);
    Serial.println(c);
    //delay(100);
}

int AVRPlatform::ledPin()
{
    return LED_BUILTIN;
}

void AVRPlatform::pinIn(uint8_t pin)
{
    pinMode(pin, INPUT);
}

void AVRPlatform::pinOut(uint8_t pin)
{
    pinMode(pin, OUTPUT);
}

void AVRPlatform::digitalSet(uint8_t pin, uint8_t value)
{
    digitalWrite(pin, value);
}

int AVRPlatform::digitalGet(uint8_t pin)
{
    return digitalRead(pin);
}

unsigned long AVRPlatform::milliseconds()
{
    return millis();
}