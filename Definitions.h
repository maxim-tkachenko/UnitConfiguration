#ifndef Definitions_h
#define Definitions_h

#define WORKUNIT_ARGS IDevice **devices, uint8_t devicesCount, IController **controllers, uint8_t controllersCount
#define HANDLER_ARGS bool *results, WORKUNIT_ARGS
#define HANDLER_ARGS_PASS results, devices, devicesCount, controllers, controllersCount

#endif
