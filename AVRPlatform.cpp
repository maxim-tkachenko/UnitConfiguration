#include "AVRPlatform.h"
#include "Arduino.h"

void AVRPlatform::print(const char c[])
{
    //Serial.println(__PRETTY_FUNCTION__);
    Serial.println(c);
    //delay(100);
}