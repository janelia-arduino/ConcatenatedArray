// ----------------------------------------------------------------------------
// EnhancedController.cpp
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "EnhancedController.h"


EnhancedController::EnhancedController()
{
}

void EnhancedController::setup()
{
  // Setup Parent
  Controller:: setup();

  // Add Storage
  server_.addMethodStorage(methods_);

  // Methods
  Method & write_led_on_method = server_.createMethod();
  write_led_on_method.attachCallback(makeFunctor((Functor0 *)0,*this,&EnhancedController::writeLedOnCallback));

  Method & write_led_off_method = server_.createMethod();
  write_led_off_method.attachCallback(makeFunctor((Functor0 *)0,*this,&EnhancedController::writeLedOffCallback));

}

void EnhancedController::writeLedOnCallback()
{
  Serial << "enhanced led on!" << endl;
}

void EnhancedController::writeLedOffCallback()
{
  Serial << "enhanced led off!" << endl;
}
