#pragma once

#include <algorithm>
#include <vector>

namespace simple_sorts {
// Пузырьковая сортировка (Bubble Sort)
void bubbleSort(std::vector<int> &values) {
  for (size_t i = 0; i < values.size() - 1; ++i) {
    for (size_t j = 0; j < values.size() - i - 1; ++j) {
      if (values[j] > values[j + 1]) {
        std::swap(values[j], values[j + 1]);
      }
    }
  }
}

// Сортировка вставками (Insertion Sort)
void insertionSort(std::vector<int> &values) {
  for (int i = 1; i < values.size(); ++i) {
    int key = values[i];
    int j = i - 1;

    while (j >= 0 && values[j] > key) {
      values[j + 1] = values[j];
      --j;
    }
    values[j + 1] = key;
  }
}

// Сортировка Шелла (Shell Sort)
void shellSort(std::vector<int> &values) {
  for (int gap = values.size() / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < values.size(); ++i) {
      int temp = values[i];
      int j;
      for (j = i; j >= gap && values[j - gap] > temp; j -= gap) {
        values[j] = values[j - gap];
      }
      values[j] = temp;
    }
  }
}
} // namespace simple_sorts
