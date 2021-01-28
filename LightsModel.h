/*
  LightsModel.h - Class to hold all the required prefs to control lights.
*/
#ifndef LightsModel_h
#define LightsModel_h

class LightsModel
{
public:
    int buttonPin;
    int relayPin;
    bool lightsState;
    bool buttonState;
    bool lastButtonState;

    // the following variable are unsigned longs because the time, measured in
    // milliseconds, will quickly become a bigger number than can be stored in an int.
    unsigned long lastDebounceTime = 0;
    bool withLed;
    int ledStripStart;
    int ledStripLenth;

    LightsModel::LightsModel(
        int buttonPin,
        int relayPin,
        bool lightsState,
        bool withLed,
        int ledStripStart,
        int ledStripLenth);
};

#endif