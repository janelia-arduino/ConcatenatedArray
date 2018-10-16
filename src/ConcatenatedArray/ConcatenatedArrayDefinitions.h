// ----------------------------------------------------------------------------
// ConcatenatedArrayDefinitions.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef CONCATENATED_ARRAY_DEFINITIONS_H
#define CONCATENATED_ARRAY_DEFINITIONS_H

#ifndef ARDUINO
#include <cstring>
#endif

template <typename T,
  size_t MAX_ARRAY_COUNT>
ConcatenatedArray<T,MAX_ARRAY_COUNT>::ConcatenatedArray()
{
  array_count_ = 0;
  size_ = 0;
  max_size_ = 0;
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
template <size_t MAX_SIZE>
void ConcatenatedArray<T,MAX_ARRAY_COUNT>::addArray(T (&values)[MAX_SIZE],
  size_t size)
{
  if (array_count_ < MAX_ARRAY_COUNT)
  {
    arrays_[array_count_].setStorage(values,size);
    ++array_count_;
    size_ += size;
    max_size_ += MAX_SIZE;
  }
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
void ConcatenatedArray<T,MAX_ARRAY_COUNT>::removeArray()
{
  if (array_count_ > 0)
  {
    --array_count_;
    size_ -= arrays_[array_count_].size();
    max_size_ -= arrays_[array_count_].max_size();
    arrays_[array_count_].clear();
  }
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
T & ConcatenatedArray<T,MAX_ARRAY_COUNT>::operator[](size_t index)
{
  return at(index);
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
T & ConcatenatedArray<T,MAX_ARRAY_COUNT>::at(size_t index)
{
  size_t size = 0;
  size_t i = index;
  for (size_t j=0; j<array_count_; ++j)
  {
    size = arrays_[j].size();
    if (i < size)
    {
      return arrays_[j][i];
    }
    else
    {
      i -= size;
    }
  }
  return arrays_[0][0]; // bad reference
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
T & ConcatenatedArray<T,MAX_ARRAY_COUNT>::front()
{
  return arrays_[0].front();
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
T & ConcatenatedArray<T,MAX_ARRAY_COUNT>::back()
{
  return arrays_[array_count_-1].back();
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
void ConcatenatedArray<T,MAX_ARRAY_COUNT>::clear()
{
  for (size_t i=0; i<array_count_; ++i)
  {
    arrays_[i].clear();
  }
  array_count_ = 0;
  size_ = 0;
  max_size_ = 0;
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
void ConcatenatedArray<T,MAX_ARRAY_COUNT>::push_back(const T & value)
{
  arrays_[array_count_-1].push_back(value);
  ++size_;
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
void ConcatenatedArray<T,MAX_ARRAY_COUNT>::pop_back()
{
  while ((array_count_ > 0) && (arrays_[array_count_-1].size() == 0))
  {
    max_size_ -= arrays_[array_count_-1].max_size();
    --array_count_;
  }
  if ((array_count_ > 0) && (arrays_[array_count_-1].size() > 0))
  {
    arrays_[array_count_-1].pop_back();
    --size_;
  }
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
size_t ConcatenatedArray<T,MAX_ARRAY_COUNT>::array_count() const
{
  return array_count_;
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
size_t ConcatenatedArray<T,MAX_ARRAY_COUNT>::size() const
{
  return size_;
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
size_t ConcatenatedArray<T,MAX_ARRAY_COUNT>::max_size() const
{
  return max_size_;
}

template <typename T,
  size_t MAX_ARRAY_COUNT>
Vector<T> & ConcatenatedArray<T,MAX_ARRAY_COUNT>::subVector(size_t index)
{
  return arrays_[index];
}

#endif
