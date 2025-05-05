#include "SingleArray.h"

#include <stdexcept>

template<typename T>
SingleArray<T>::SingleArray(size_t size) {
  if (size > 0) {
    Size = size;
    Count = 0;
    Data = new T[Size];
    Realloc++;
    Name = "Фиксированный массив";
  }
}

template<typename T>
T SingleArray<T>::value(size_t index) const {
  if (index < Count)
    return Data[index];
  else
    throw std::out_of_range("invalid index!");
}

template<typename T>
void SingleArray<T>::put(T value) {
  if (Size == Count)
    throw std::out_of_range("all cells are occupied!");

  Data[Count] = value;
  Count++;
}

template<typename T>
void SingleArray<T>::add(T value, size_t index) {
  if (Size == Count)
    throw std::out_of_range("all cells are occupied!");

  if (index > Count)
    throw std::invalid_argument("index > Count!");

  if (index >= Size)
    throw std::out_of_range("invalid index!");

  if (index == Count) {
    put(value);

    return;
  }
  T *NewData = new T[Size];
  Realloc++;

  for (size_t i = 0; i < Count; i++) {
    if (i == index) {
      *NewData++ = value;

      continue;
    }
    *NewData++ = *Data++;
  }
  Count++;
  delete []Data;
  Data = NewData;
}

template<typename T>
T SingleArray<T>::remove(size_t index) {
  if (index >= Count)
    throw std::out_of_range("invalid index!");

  if (index + 1 == Count) {
    Count--;
    return Data[index];
  }
  else {
    T *NewData = new T[Size];
    Realloc++;

    T removedValue;
    for (size_t i = 0; i < Count; i++) {
      if (i == index) {
        removedValue = Data[index];
        continue;
      }
      *NewData++ = *Data++;
    }
    delete []Data;
    Data = NewData;
    Count--;

    return removedValue;
  }
}
