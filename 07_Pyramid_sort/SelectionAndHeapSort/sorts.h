#pragma once

#include <algorithm>
#include <vector>


namespace sorts {
// Алгоритм сортировки выбором (Selection Sort)
void selectionSort(std::vector<int> &values) {
  for (size_t i = 0; i < values.size() - 1; ++i) {
    size_t minIndex = i;
    for (size_t j = i + 1; j < values.size(); ++j) {
      if (values[j] < values[minIndex]) {
        minIndex = j;
      }
    }
    std::swap(values[i], values[minIndex]); // Меняем местами минимальный элемент и первый элемент
  }
}

// Алгоритм пирамидальной сортировки (Heap Sort)
void heapify(std::vector<int> &values, size_t n, size_t root) {
  size_t largest = root;   // Инициализируем наибольший элемент как корень
  size_t leftChild = 2 * root + 1;  // Левый потомок = 2*i + 1
  size_t rightChild = 2 * root + 2; // Правый потомок = 2*i + 2

  // Если левый потомок больше корня
  if (leftChild < n && values[leftChild] > values[largest])
    largest = leftChild;

  // Если правый потомок больше, чем самый большой элемент на данный момент
  if (rightChild < n && values[rightChild] > values[largest])
    largest = rightChild;

  // Если самый большой элемент не корень
  if (largest != root) {
    std::swap(values[root], values[largest]);

    // Рекурсивно применяем процедуру к дереву поддерева
    heapify(values, n, largest);
  }
}

void heapSort(std::vector<int> &values) {
  size_t n = values.size();

  // Строим max-heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(values, n, i);

  // Один за другим извлекаем элементы из кучи
  for (int i = n - 1; i >= 0; i--) {
    // Перемещаем текущий корневой элемент в конец
    std::swap(values[0], values[i]);

    // Применяем процедуру heapify к уменьшенному размеру кучи
    heapify(values, i, 0);
  }
}
} // namespace sorts
