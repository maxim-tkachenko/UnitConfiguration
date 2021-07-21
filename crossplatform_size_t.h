#ifndef crossplatform_size_t_h
#define crossplatform_size_t_h

#ifdef __AVR
#include "Arduino.h"
#else
#include "_size_t.h"
#endif

#endif