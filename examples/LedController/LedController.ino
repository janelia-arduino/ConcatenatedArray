#include "Arduino.h"
#include "Streaming.h"
#include "ConcatenatedArray.h"
#include "Functor.h"

#include "Constants.h"
#include "Method.h"
#include "Controller.h"
#include "EnhancedController.h"


EnhancedController enhanced_controller;

void setup()
{
  enhanced_controller.setup();
}

void loop()
{
  enhanced_controller.update();
}
