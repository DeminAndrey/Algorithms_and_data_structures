#include "HeapSort.h"

void HeapSort::heapify(std::vector<int>& arr, int n, int rootIndex, StatisticsCollector& stats) const {
  int largest = rootIndex;
  int leftChild = 2 * rootIndex + 1;
  int rightChild = 2 * rootIndex + 2;

  if (leftChild < n && arr[leftChild] > arr[largest]) {
    largest = leftChild;
    stats.incrementComparisons();
  }

  if (rightChild < n && arr[rightChild] > arr[largest]) {
    largest = rightChild;
    stats.incrementComparisons();
  }

  if (largest != rootIndex) {
    std::swap(arr[rootIndex], arr[largest]);
    stats.incrementSwaps();
    heapify(arr, n, largest, stats);
  }
}

void HeapSort::sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const {
  int n = arr.size();

  // Строим кучу
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i, stats);
  }

  // Сортируем
  for (int i = n - 1; i > 0; i--) {
    std::swap(arr[0], arr[i]);
    stats.incrementSwaps();
    heapify(arr, i, 0, stats);
  }
}
