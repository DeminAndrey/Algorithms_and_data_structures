#include "BubbleSort.h"

void BubbleSort::sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const {
  bool swapped;
  do {
    swapped = false;
    for (size_t i = 1; i < arr.size(); ++i) {
      if (arr[i - 1] > arr[i]) {
        std::swap(arr[i], arr[i - 1]);
        stats.incrementSwaps();
        swapped = true;
      }
      stats.incrementComparisons();
    }
  } while (swapped);
}
