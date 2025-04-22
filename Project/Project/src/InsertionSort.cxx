#include "InsertionSort.h"

void InsertionSort::sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const {
  for (size_t i = 1; i < arr.size(); ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j]; // сдвиг вправо
      stats.incrementSwaps();
      j--;
      stats.incrementComparisons();
    }
    arr[j+1] = key;
    stats.incrementComparisons(); // проверка условия выхода из цикла
  }
}
