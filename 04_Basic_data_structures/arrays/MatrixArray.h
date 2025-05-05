#pragma once

#include <string>

/**
 * @brief The MatrixArray класс свободного массива
 */
template<typename T>
class MatrixArray {
private:
  size_t Lenght = 1; // количество строк
  const size_t Size = 10; // количество элементов в строках
  size_t Count = 0; // количество занятых элементов массива
  T** Data = nullptr; // указатель на первый элемент первой строки
  size_t Realloc = 0; // количество выделений памяти
  std::string Name = "Free array"; // наименование массива

public:
  MatrixArray();

  ~MatrixArray();

  T value(size_t index) const;

  void put(T value);

  void add(T value, size_t index);

  size_t realloc() const { return Realloc; }

  std::string name() const { return Name; }

  void resetRealloc() { Realloc = 0; }
};

template class MatrixArray<int>;
