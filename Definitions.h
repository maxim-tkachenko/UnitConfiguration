#ifndef Definitions_h
#define Definitions_h

#define WORKUNIT_ARGS IDevice **devices, uint8_t devicesCount, IController **controllers, uint8_t controllersCount
#define HANDLER_ARGS bool *results, WORKUNIT_ARGS
#define HANDLER_ARGS_PASS results, devices, devicesCount, controllers, controllersCount
#define REAL_BOARD __AVR || ARDUINO_ESP8266_NODEMCU

#define D0 #if _AVR 9 #elif ARDUINO_ESP8266_NODEMCU 0 #else - 1
#define D1 #if _AVR 10 #elif ARDUINO_ESP8266_NODEMCU 1 #else - 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define D8 8

#endif
