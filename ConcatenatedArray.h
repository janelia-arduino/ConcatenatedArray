// ----------------------------------------------------------------------------
// ConcatenatedArray.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef CONCATENATED_ARRAY_H
#define CONCATENATED_ARRAY_H

#ifdef ARDUINO
    #if ARDUINO >= 100
        #include <Arduino.h>
    #else
        #include <WProgram.h>
    #endif
#else
    #include <cstddef>
#endif

#include "Vector.h"


template <typename T, size_t MAX_ARRAY_COUNT>
class ConcatenatedArray
{
public:
  ConcatenatedArray();
  template <size_t MAX_SIZE>
  void addArray(T (&values)[MAX_SIZE], size_t size=0);
  T & operator[](const size_t index);
  T & at(const size_t index);
  T & front();
  T & back();
  void clear();
  void push_back(const T & value);
  void pop_back();
  size_t array_count() const;
  size_t size() const;
  size_t max_size() const;
  const Vector<T> & subVector(const size_t index) const;

private:
  Vector<T> arrays_[MAX_ARRAY_COUNT];
  size_t array_count_;
  size_t size_;
  size_t max_size_;
};

template <typename T, size_t MAX_ARRAY_COUNT>
inline Print & operator <<(Print & stream, const ConcatenatedArray<T,MAX_ARRAY_COUNT> & array)
{
  stream.print("[");
  size_t size = array.size();
  for (size_t i=0; i<size; ++i)
  {
    if (i != 0)
    {
      stream.print(",");
    }
    stream.print(array[i]);
  }
  stream.print("]");
  return stream;
}

#include "ConcatenatedArrayDefinitions.h"

#endif
