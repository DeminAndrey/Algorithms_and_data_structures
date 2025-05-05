#include "FactorArray.h"

#include <stdexcept>

template<typename T>
FactorArray<T>::FactorArray(size_t size) {
  if (size > 0) {
    Size = size;
    Count = 0;
    Data = new T[Size];
    Realloc++;
    Name = "Dynamic array * 2";
  }
}

template<typename T>
T FactorArray<T>::value(size_t index) const {
  if (index < Count)
    return Data[index];
  else
    throw std::out_of_range("invalid index!");
}

template<typename T>
void FactorArray<T>::put(T value) {
  if (Count < Size) {
    Data[Count] = value;
    Count++;
  }
  else {
    Size *= 2;
    T *NewData = new T[Size];
    Realloc++;

    for (size_t i = 0; i < Count; i++)
      NewData[i] = Data[i];

    NewData[Count] = value;
    Count++;
    Data = NewData;
  }
}

template<typename T>
void FactorArray<T>::add(T value, size_t index) {
  if (index == Count) {
    if (Count == Size)
      put(value);
    else {
      Data[Count] = value;
      Count++;
    }
  }
  else if (index > Count) {
    throw std::out_of_range("invalid index!");
  }
  else {
    if (Count == Size) {
      Size *= 2;
    }
    T *NewData = new T[Size];
    Realloc++;

    for (size_t i = 0; i < Count; i++) {
      if (i == index) {
        NewData[i] = value;

        continue;
      }
      NewData[i] = Data[i];
    }
    Count++;
    Data = NewData;
  }
}

template<typename T>
T FactorArray<T>::remove(size_t index) {
  if (index >= Count)
    throw std::out_of_range("invalid index!");

  if (index + 1 == Count) {
    Count--;
    return Data[index];
  }
  else {
    T removedValue = Data[index];

    for (size_t i = index + 1; i < Count; i++)
      Data[i - 1] = Data[i];

    Count--;

    return removedValue;
  }
}
