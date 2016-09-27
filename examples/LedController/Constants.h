// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "Arduino.h"


namespace constants
{
enum{METHOD_ARRAY_COUNT_MAX=4};
enum{INTERNAL_METHOD_COUNT_MAX=2};
enum{CONTROLLER_METHOD_COUNT_MAX=2};
enum{ENHANCED_CONTROLLER_METHOD_COUNT_MAX=2};

extern const size_t baudrate;

extern const size_t led_pin;

}
#endif
