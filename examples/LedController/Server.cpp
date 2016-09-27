// ----------------------------------------------------------------------------
// Server.cpp
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Server.h"


Server::Server()
{
  setup();
}

void Server::setup()
{
  // Pin Setup
  pinMode(constants::led_pin, OUTPUT);

  // Add Storage
  addMethodStorage(internal_methods_);

  // Methods
  Method & led_on_method = createMethod();
  led_on_method.attachCallback(makeFunctor((Functor0 *)0,*this,&Server::setLedOnCallback));

  Method & led_off_method = createMethod();
  led_off_method.attachCallback(makeFunctor((Functor0 *)0,*this,&Server::setLedOffCallback));

}

template <size_t MAX_SIZE>
void Server::addMethodStorage(Method (&methods)[MAX_SIZE])
{
  methods_.addArray(methods);
}

Method & Server::createMethod()
{
  methods_.push_back(Method());
  return methods_.back();
}

size_t Server::getMethodCount()
{
  return methods_.size();
}

void Server::callMethod(size_t method_index)
{
  if (method_index < getMethodCount())
  {
    Serial << "methods_[" << method_index << "].callback()" << endl;
    methods_[method_index].callback();
  }
}

void Server::setLedOnCallback()
{
  digitalWrite(constants::led_pin,HIGH);
}

void Server::setLedOffCallback()
{
  digitalWrite(constants::led_pin,LOW);
}
