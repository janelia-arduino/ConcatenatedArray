// ----------------------------------------------------------------------------
// ConcatenatedArrayDefinitions.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef CONCATENATED_ARRAY_DEFINITIONS_H
#define CONCATENATED_ARRAY_DEFINITIONS_H

#ifndef ARDUINO
#include <cstring>
#endif

template <typename T, size_t ARRAY_COUNT_MAX>
ConcatenatedArray<T, ARRAY_COUNT_MAX>::ConcatenatedArray()
{
  array_count_ = 0;
}

template <typename T>
template <size_t MAX_SIZE>
void ConcatenatedArray<T, ARRAY_COUNT_MAX>::addArray(T (&values)[MAX_SIZE], size_t size)
{
  if (array_count_ < ARRAY_COUNT_MAX)
  {
    arrays_[array_count_].setStorage(values,size);
    ++array_count_;
  }
}

template <typename T, size_t ARRAY_COUNT_MAX>
T & ConcatenatedArray<T, ARRAY_COUNT_MAX>::operator[](const size_t i)
{
  return arrays_[i];
}

template <typename T, size_t ARRAY_COUNT_MAX>
T & ConcatenatedArray<T, ARRAY_COUNT_MAX>::at(const size_t i)
{
  return arrays_[i];
}

template <typename T, size_t ARRAY_COUNT_MAX>
T & ConcatenatedArray<T, ARRAY_COUNT_MAX>::front()
{
  return arrays_[0].front();
}

template <typename T, size_t ARRAY_COUNT_MAX>
T & ConcatenatedArray<T, ARRAY_COUNT_MAX>::back()
{
  return arrays_[array_count__-1].back();
}

template <typename T, size_t ARRAY_COUNT_MAX>
void ConcatenatedArray<T, ARRAY_COUNT_MAX>::clear()
{
  for (size_t i=0; i<array_count_; ++i)
  {
    arrays_[i].clear();
  }
  array_count_ = 0;
}

// template <typename T, size_t ARRAY_COUNT_MAX>
// template <typename U>
// void ConcatenatedArray<T, ARRAY_COUNT_MAX>::fill(const U & value)
// {
//   assign(ARRAY_COUNT_MAX,value);
// }

// template <typename T, size_t ARRAY_COUNT_MAX>
// template <typename U, size_t N>
// void ConcatenatedArray<T, ARRAY_COUNT_MAX>::fill(const U (&values)[N])
// {
//   assign(N,values);
// }

// template <typename T, size_t ARRAY_COUNT_MAX>
// template <typename U, size_t N>
// void ConcatenatedArray<T, ARRAY_COUNT_MAX>::fill(const ConcatenatedArray<U,N> & values)
// {
//   assign(values.size(),values);
// }

// template <typename T, size_t ARRAY_COUNT_MAX>
// template <typename U>
// void ConcatenatedArray<T, ARRAY_COUNT_MAX>::assign(const size_t n, const U & value)
// {
//   size_t assign_size = ((n < ARRAY_COUNT_MAX) ? n : ARRAY_COUNT_MAX);
//   size_ = assign_size;
//   for (size_t i=0; i<assign_size; i++)
//   {
//     arrays_[i] = value;
//   }
// }

// template <typename T, size_t ARRAY_COUNT_MAX>
// template <typename U, size_t N>
// void ConcatenatedArray<T, ARRAY_COUNT_MAX>::assign(const size_t n, const U (&values)[N])
// {
//   size_t n_smallest = ((n < N) ? n : N);
//   size_t assign_size = ((n_smallest < ARRAY_COUNT_MAX) ? n_smallest : ARRAY_COUNT_MAX);
//   size_ = assign_size;
//   for (size_t i=0; i<assign_size; i++)
//   {
//     arrays_[i] = values[i];
//   }
// }

// template <typename T, size_t ARRAY_COUNT_MAX>
// template <typename U, size_t N>
// void ConcatenatedArray<T, ARRAY_COUNT_MAX>::assign(const size_t n, const ConcatenatedArray<U,N> & values)
// {
//   size_t n_smallest = ((n < values.size()) ? n : values.size());
//   size_t assign_size = ((n_smallest < ARRAY_COUNT_MAX) ? n_smallest : ARRAY_COUNT_MAX);
//   size_ = assign_size;
//   for (size_t i=0; i<assign_size; i++)
//   {
//     arrays_[i] = values[i];
//   }
// }

template <typename T, size_t ARRAY_COUNT_MAX>
void ConcatenatedArray<T, ARRAY_COUNT_MAX>::push_back(const T & value)
{
  arrays_[array_count_-1].push_back(value);
}

template <typename T, size_t ARRAY_COUNT_MAX>
void ConcatenatedArray<T, ARRAY_COUNT_MAX>::pop_back()
{
  while ((array_count_ > 0) && (arrays_[array_count_-1].size() == 0))
  {
    --array_count_;
  }
  if ((array_count_ > 0) && (arrays_[array_count_-1].size() > 0))
  {
    arrays_[array_count_-1].pop_back();
  }
}

template <typename T, size_t ARRAY_COUNT_MAX>
size_t ConcatenatedArray<T, ARRAY_COUNT_MAX>::size()
{
  size_t size = 0;
  for (size_t i=0; i<array_count_; ++i)
  {
    size += arrays_[i].size();
  }
  return size;
}

template <typename T, size_t ARRAY_COUNT_MAX>
size_t ConcatenatedArray<T, ARRAY_COUNT_MAX>::max_size()
{
  size_t max_size = 0;
  for (size_t i=0; i<array_count_; ++i)
  {
    max_size += arrays_[i].max_size();
  }
  return max_size;
}

// template <typename T, size_t ARRAY_COUNT_MAX>
// bool ConcatenatedArray<T, ARRAY_COUNT_MAX>::empty()
// {
//   return size_ == 0;
// }

// template <typename T, size_t ARRAY_COUNT_MAX>
// bool ConcatenatedArray<T, ARRAY_COUNT_MAX>::full()
// {
//   return size_ == ARRAY_COUNT_MAX;
// }

// template <typename T, size_t ARRAY_COUNT_MAX>
// T * ConcatenatedArray<T, ARRAY_COUNT_MAX>::data()
// {
//   return arrays_;
// }

#endif
