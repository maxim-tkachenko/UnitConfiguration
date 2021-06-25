#ifndef ILight_h
#define ILight_h

class ILight {
    // if debug
    static const int ledPin = 13;
    volatile bool _initialized = false;

  public:
    int buttonPin;
    bool lightsState;
    bool buttonState;
    bool lastButtonState;

    // the following variable are unsigned longs because the time, measured in
    // milliseconds, will quickly become a bigger number than can be stored in an int.
    unsigned long lastDebounceTime = 0;

    void init();
    virtual void set(bool state);

    void log(char message[]);

  protected:
    ILight(
      int buttonPin,
      bool initialState);
};

#endif
