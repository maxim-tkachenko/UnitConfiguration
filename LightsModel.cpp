/*
  LightsModel.h - Class to hold all the required prefs to control lights.
*/

#include "LightsModel.h"

LightsModel::LightsModel(
    int buttonPin,
    int relayPin,
    bool lightsState,
    bool withLed,
    int ledStripStart,
    int ledStripLenth)
{
    this->buttonPin = buttonPin;
    this->relayPin = relayPin;
    this->lightsState = lightsState;
    this->withLed = withLed;
    this->ledStripStart = ledStripStart;
    this->ledStripLenth = ledStripLenth;
}