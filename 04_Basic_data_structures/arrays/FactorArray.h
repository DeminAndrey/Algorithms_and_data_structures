#pragma once

#include "Array.h"

/**
 * @brief The FactorArray класс динамического массива
 */
template<typename T>
class FactorArray : public Array<T>
{
public:
  explicit FactorArray(size_t size = 1);

  T value(size_t index) const override;

  void put(T value) override;

  void add(T value, size_t index) override;

  T remove(size_t index) override;
};

template class FactorArray<int>;
