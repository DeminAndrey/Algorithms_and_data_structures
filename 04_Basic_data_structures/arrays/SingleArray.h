#pragma once

#include "Array.h"

/**
 * @brief The SingleArray класс фиксированного массива
 */
template<typename T>
class SingleArray : public Array<T>
{
public:
  explicit SingleArray(size_t size = 1);

  ~SingleArray() override = default;

  T value(size_t index) const override;

  void put(T value) override;

  void add(T value, size_t index) override;

  T remove(size_t index) override;
};

template class SingleArray<int>;
