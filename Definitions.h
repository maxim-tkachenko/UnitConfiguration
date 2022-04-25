#ifndef Definitions_h
#define Definitions_h

#define WORKUNIT_ARGS IDevice **devices, uint8_t devicesCount, IController **controllers, uint8_t controllersCount
#define HANDLER_ARGS bool *results, WORKUNIT_ARGS
#define HANDLER_ARGS_PASS results, devices, devicesCount, controllers, controllersCount

#define WIFI_NETWORK_CONNECTION
// #define WIRE_NETWORK_CONNECTION

#if defined(ARDUINO_ARCH_ESP8266)
#define REAL_BOARD true
// pinout for node mcu
#define DPIN0 16 // ? x
#define DPIN1 5
#define DPIN2 4
#define DPIN3 0
#define DPIN4 2
#define DPIN5 14
#define DPIN6 12
#define DPIN7 13
#define DPIN8 15
#define DPIN9 -1
#define DPIN10 -1

#elif defined(__AVR)
#define REAL_BOARD true
#define DPIN0 11
#define DPIN1 12
#define DPIN2 2
#define DPIN3 3
#define DPIN4 4
#define DPIN5 5
#define DPIN6 6
#define DPIN7 7
#define DPIN8 8
#define DPIN9 9
#define DPIN10 10

#else
#define REAL_BOARD false
#endif

#endif
