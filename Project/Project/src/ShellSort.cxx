#include "ShellSort.h"

void ShellSort::shellSortImpl(std::vector<int>& arr, StatisticsCollector& stats) const {
  int n = arr.size();
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j = i;
      while (j >= gap && arr[j - gap] > temp) {
        arr[j] = arr[j - gap];
        stats.incrementSwaps();
        j -= gap;
        stats.incrementComparisons();
      }
      arr[j] = temp;
      stats.incrementComparisons();
    }
  }
}

void ShellSort::sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const {
  shellSortImpl(arr, stats);
}
