#pragma once

#include <string>

template<typename T>
class Array {
protected:
  size_t Size = 0; // длина массива
  size_t Count = 0; // количество занятых элементов массива
  T* Data = nullptr; // указатель на первый элемент массива
  size_t Realloc = 0; // количество выделений памяти
  std::string Name; // наименование массива

public:
  virtual ~Array() {
    if (Data != nullptr)
      delete []Data;
  }

  /**
   * @brief realloc геттер количества реаллокаций памяти
   */
  size_t realloc() const { return Realloc; }

  /**
   * @brief size геттер количества занятых элементов массива
   */
  size_t size() const { return Count; }

  /**
   * @brief name геттер имени / типа массива
   */
  std::string name() const { return Name; }

  /**
   * @brief resetRealloc сброс параметра к начальному значению
   */
  void resetRealloc() { Realloc = 0; }

  /**
   * @brief value получить значение из массива по заданному индексу
   * @param index индекс ячейки
   * @return значение
   */
  virtual T value(size_t index) const = 0;

  /**
   * @brief put положить элемент в конец массива
   * @param value новый элемент
   */
  virtual void put(T value) = 0;

  /**
   * @brief add разместить новый элемент по заданному индексу
   * @param value новый элемент
   * @param index индекс
   */
  virtual void add(T value, size_t index) = 0;

  /**
   * @brief remove удалить элемент из массива по заданному индексу
   * @param index индекс
   * @return извлеченный элемент из массива
   */
  virtual T remove(size_t index) = 0;
};
