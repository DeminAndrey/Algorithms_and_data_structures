#include "SelectionSort.h"

void SelectionSort::sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const {
  int n = arr.size();

  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
      stats.incrementComparisons();
    }
    if (min_idx != i) {
      std::swap(arr[i], arr[min_idx]);
      stats.incrementSwaps();
    }
  }
}
