// ----------------------------------------------------------------------------
// Controller.cpp
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Controller.h"


Controller::Controller()
{
}

void Controller::setup()
{
  // Add Storage
  server_.addMethodStorage(methods_);

  // Methods
  Method & write_led_on_method = server_.createMethod();
  write_led_on_method.attachCallback(makeFunctor((Functor0 *)0,*this,&Controller::writeLedOnCallback));

  Method & write_led_off_method = server_.createMethod();
  write_led_off_method.attachCallback(makeFunctor((Functor0 *)0,*this,&Controller::writeLedOffCallback));

  // Setup Streams
  Serial.begin(constants::baudrate);
}

void Controller::update()
{
  size_t method_count = server_.getMethodCount();
  Serial << "method_count = " << method_count << endl;
  for (size_t i=0; i<method_count; ++i)
  {
    Serial << "server_.callMethod(" << i << ")" << endl;
    server_.callMethod(i);
    delay(1000);
  }
}

void Controller::writeLedOnCallback()
{
  Serial << "led on" << endl;
}

void Controller::writeLedOffCallback()
{
  Serial << "led off" << endl;
}
