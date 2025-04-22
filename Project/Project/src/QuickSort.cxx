#include "QuickSort.h"

// Основная логика сортировки методом разделения
void QuickSort::quickSortHelper(std::vector<int>& arr, int low, int high, StatisticsCollector& stats) const {
  if (low < high) {
    int pi = partition(arr, low, high, stats);
    quickSortHelper(arr, low, pi - 1, stats);
    quickSortHelper(arr, pi + 1, high, stats);
  }
}

// Процедура разделения массива вокруг опорного элемента
int QuickSort::partition(std::vector<int>& arr, int low, int high, StatisticsCollector& stats) const {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; ++j) {
    if (arr[j] < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
      stats.incrementSwaps();
    }
    stats.incrementComparisons();
  }
  std::swap(arr[i + 1], arr[high]);
  stats.incrementSwaps();
  return i + 1;
}

// Основной метод сортировки
void QuickSort::sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const {
  quickSortHelper(arr, 0, arr.size()-1, stats);
}
