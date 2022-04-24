#ifndef Definitions_h
#define Definitions_h

#define WORKUNIT_ARGS IDevice **devices, uint8_t devicesCount, IController **controllers, uint8_t controllersCount
#define HANDLER_ARGS bool *results, WORKUNIT_ARGS
#define HANDLER_ARGS_PASS results, devices, devicesCount, controllers, controllersCount
#define REAL_BOARD __AVR || ARDUINO_ESP8266_NODEMCU

#define WIFI_NETWORK_CONNECTION
// #define WIRE_NETWORK_CONNECTION

#ifndef ARDUINO_ESP8266_NODEMCU
#define DPIN0 9
#define DPIN1 10
#define DPIN2 2
#define DPIN3 3
#define DPIN4 4
#define DPIN5 5
#define DPIN6 6
#define DPIN7 7
#define DPIN8 8
#endif

// pinout for mode mcu
// #define D0 16? x
// #define D1 5
// #define D2 4
// #define D3 0
// #define D4 2
// #define D5 14
// #define D6 12
// #define D7 13
// #define D8 15

#endif
