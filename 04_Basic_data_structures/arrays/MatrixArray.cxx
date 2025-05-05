#include "MatrixArray.h"

template<typename T>
MatrixArray<T>::MatrixArray() {
  Data = new T*[Lenght];
  Data[0] = new T[Size];
}

template<typename T>
MatrixArray<T>::~MatrixArray() {
  delete []Data;
}

template<typename T>
T MatrixArray<T>::value(size_t index) const {
  return Data[index / Size][index % Size];
}

template<typename T>
void MatrixArray<T>::put(T value) {
  size_t row = Count / Size;
  size_t col = Count % Size;
  if (row < Lenght) {
    Data[row][col] = value;
    Count++;
  }
  else {
    Realloc++;
    T **arr = new T*[row + 1];
    arr[row] = Data[row];

    Data = arr;
    Data[row] = new T[Size];
    Data[row][col] = value;
    Count++;
  }
}

template<typename T>
void MatrixArray<T>::add(T value, size_t index) {
  Data[index / Size][index % Size] = value;
}
