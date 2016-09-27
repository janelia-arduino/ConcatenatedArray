// ----------------------------------------------------------------------------
// Server.h
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef SERVER_H
#define SERVER_H
#include "Functor.h"
#include "ConcatenatedArray.h"
#include "Streaming.h"

#include "Constants.h"
#include "Method.h"


class Server
{
public:
  Server();
  template <size_t MAX_SIZE>
  void addMethodStorage(Method (&methods)[MAX_SIZE]);
  Method & createMethod();
  size_t getMethodCount();
  void callMethod(size_t method_index);

private:
  Method internal_methods_[constants::INTERNAL_METHOD_COUNT_MAX];
  ConcatenatedArray<Method,constants::METHOD_ARRAY_COUNT_MAX> methods_;
  void setup();

  void setLedOnCallback();
  void setLedOffCallback();
};

#endif
