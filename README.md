# UnitConfiguration
This is a library for easily managing various numbers of your devices. Extremely extensible unit configuration allows to combine devices and controllers in a way you need with handy support of your project-specific logic.

Platform-specific API is stored in a single class for easily adding more architectures (avr and x86_x64 works for now).
`Runner` class is there to allow to develop and debug code in your favourite C/C++ IDE and than deploy to microcontroller via native one (works well for Arduino IDE + VS Code).

## Examples:

Setup primitive devices which can be controled via relay and button, just specify data pins:

```C++
add(new WorkUnit(new GenericDevice(2), new PushButtonDebounced(12)));
```

Led strip support using [FastLED](https://github.com/FastLED/FastLED):
```C++
add(new WorkUnit(FastLedLight::create<4>(200), new PushButtonDebounced(12)));
```
Have more light zones or devices which would like to control via single button?
```C++
add(
    new WorkUnit(
        new IDevice *[2]
        {
            new GenericDevice(2),
            new GenericDevice(3),
        },
        2,
        new PushButtonDebounced(12)));
```

Want to control single device from different places?
```C++
add(
    new WorkUnit(
        new GenericDevice(2),
        new IController *[2]
        {
            new PushButtonDebounced(11),
            new PushButtonDebounced(12),
        },
        2));
```

Turn off after certain time of inactivity?
```C++
add(
    new WorkUnit(
        new GenericDevice(2),
        new PushButtonDebounced(12),
        new TimeoutHandler(1000 * 60 * 15))); // 15 mins
```

Any other custom actions can be handled as well, just create new class derived from `IHandler` and write your own logic. Any custom devices or controllers can be added using `IDevice` or `IController` respectively.

### Complete example

```C++
#include <UnitConfiguration.h>
#include <TimeoutHandler.h>

Runner runner;

class TestConfiguration : public IConfiguration<3>
{
public:
  TestConfiguration()
  {
    add(new WorkUnit(new GenericDevice(2), new PushButtonDebounced(12)));
    add(new WorkUnit(FastLedLight::create<3>(200), new PushButtonDebounced(11)));
    add(
        new WorkUnit(
            new IDevice *[2]
            {
              new GenericDevice(4),
              new GenericDevice(5),
            },
            2,
            new IController *[2]
            {
              new PushButtonDebounced(9),
              new PushButtonDebounced(10),
            },
            2,
            new TimeoutHandler(1000 * 60 * 15))); // 15 mins
  }
};

void setup()
{
  runner.init();
  runner.setConfig(new TestConfiguration());
}

void loop()
{
  runner.loop();
}
```

## Roadmap:

- ~~Custom turn on/off animations support.~~
- Switch button/reed switch controller support.
- Push button multi clicks support (double-click, long-click, etc).
- MQTT controller support to allow to control devices from remote.
