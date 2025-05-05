#pragma once

#include "Array.h"

/**
 * @brief The VectorArray класс динамического массива
 */
template<typename T>
class VectorArray : public Array<T>
{
public:
  explicit VectorArray(size_t size = 1);

  T value(size_t index) const override;

  void put(T value) override;

  void add(T value, size_t index) override;

  T remove(size_t index) override;
};

template class VectorArray<int>;
