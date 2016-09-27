// ----------------------------------------------------------------------------
// Controller.h
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Functor.h"
#include "Streaming.h"

#include "Constants.h"
#include "Server.h"
#include "Method.h"


class Controller
{
public:
  Controller();
  void setup();
  void update();

  Server server_;

private:
  Method methods_[constants::CONTROLLER_METHOD_COUNT_MAX];

  void writeLedOnCallback();
  void writeLedOffCallback();
};

#endif
