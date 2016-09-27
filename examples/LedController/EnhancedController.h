// ----------------------------------------------------------------------------
// EnhancedController.h
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef ENHANCED_CONTROLLER_H
#define ENHANCED_CONTROLLER_H
#include "Functor.h"
#include "Streaming.h"

#include "Constants.h"
#include "Server.h"
#include "Method.h"
#include "Controller.h"


class EnhancedController : public Controller
{
public:
  EnhancedController();
  void setup();

private:
  Method methods_[constants::ENHANCED_CONTROLLER_METHOD_COUNT_MAX];

  void writeLedOnCallback();
  void writeLedOffCallback();
};

#endif
