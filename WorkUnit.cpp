#include "WorkUnit.h"
#include "ControllerHandler.h"

WorkUnit::WorkUnit(IDevice *device, IController *controller)
    : WorkUnit(device, controller, new ControllerHandler())
{
    traceme;
}

WorkUnit::WorkUnit(IDevice *device, IController *controller, IHandler *handler)
    : WorkUnit(
          device,
          controller,
          new IHandler *[1]
          { handler },
          1)
{
    traceme;
}

WorkUnit::WorkUnit(IDevice *device, IController *controller, IHandler **handlers, uint8_t handlersCount)
    : WorkUnit(
          device,
          new IController *[1]
          { controller },
          1,
          handlers,
          handlersCount)
{
    traceme;
}

WorkUnit::WorkUnit(IDevice *device, IController **controllers, uint8_t controllersCount)
    : WorkUnit(
          device,
          controllers,
          controllersCount,
          new ControllerHandler())
{
    traceme;
}

WorkUnit::WorkUnit(IDevice *device, IController **controllers, uint8_t controllersCount, IHandler *handler)
    : WorkUnit(
          device,
          controllers,
          controllersCount,
          new IHandler *[1]
          {
              handler
          },
          1)
{
    traceme;
}

WorkUnit::WorkUnit(IDevice *device, IController **controllers, uint8_t controllersCount, IHandler **handlers, uint8_t handlersCount)
    : WorkUnit(
          new IDevice *[1]
          { device },
          1,
          controllers,
          controllersCount,
          handlers,
          handlersCount)
{
    traceme;
}

WorkUnit::WorkUnit(IDevice **devices, uint8_t devicesCount, IController *controller)
    : WorkUnit(
          devices,
          devicesCount,
          new IController *[1]
          { controller },
          1,
          new ControllerHandler())
{
    traceme;
}

WorkUnit::WorkUnit(IDevice **devices, uint8_t devicesCount, IController *controller, IHandler *handler)
    : WorkUnit(
          devices,
          devicesCount,
          new IController *[1]
          { controller },
          1,
          handler)
{
    traceme;
}

WorkUnit::WorkUnit(IDevice **devices, uint8_t devicesCount, IController *controller, IHandler **handlers, uint8_t handlersCount)
    : WorkUnit(
          devices,
          devicesCount,
          new IController *[1]
          { controller },
          1,
          handlers,
          handlersCount)
{
    traceme;
}

WorkUnit::WorkUnit(WORKUNIT_ARGS)
    : WorkUnit(devices, devicesCount, controllers, controllersCount, new ControllerHandler())
{
    traceme;
}

WorkUnit::WorkUnit(WORKUNIT_ARGS, IHandler *handler)
    : WorkUnit(
          devices,
          devicesCount,
          controllers,
          controllersCount,
          new IHandler *[1]
          {
              handler
          },
          1)
{
    traceme;
}

WorkUnit::WorkUnit(WORKUNIT_ARGS, IHandler **handlers, uint8_t handlersCount)
    : _devices(devices),
      _devicesCount(devicesCount),
      _controllers(controllers),
      _controllersCount(controllersCount),
      _handlers(handlers),
      _handlersCount(handlersCount),
      _handlersResults(new bool[handlersCount])
{
    traceme;
}

// TODO: this could throw an exception when freeing already freed pointer.
WorkUnit::~WorkUnit()
{
    traceme;

    for (uint8_t ci = 0; ci < _controllersCount; ci++)
    {
        delete _controllers[ci];
    }

    delete[] _controllers;

    for (uint8_t di = 0; di < _devicesCount; di++)
    {
        delete _devices[di];
    }

    delete[] _devices;

    for (uint8_t hi = 0; hi < _handlersCount; hi++)
    {
        delete _handlers[hi];
    }

    delete[] _handlers;
    delete[] _handlersResults;
}

void WorkUnit::check()
{
    // TODO: is it possible to invert this logic?
    //       we should try to iterate throught the controllers and execute
    //       all the handlers if any (controller) has been triggered.
    for (uint8_t hi = 0; hi < _handlersCount; hi++)
    {
        _handlersResults[hi] = _handlers[hi]->execute(_handlersResults, _devices, _devicesCount, _controllers, _controllersCount);

        // ensure timing-sensitive controllers (like PushButtonMulticlick) to work
        for (uint8_t ci = 0; ci < _controllersCount; ci++)
        {
            _controllers[ci]->tick();
        }
    }
}