#include "MergeSort.h"

void MergeSort::merge(std::vector<int>& arr, int l, int m, int r, StatisticsCollector& stats) const {
  int n1 = m - l + 1;
  int n2 = r - m;

  std::vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
    stats.incrementComparisons();
  }

  while (i < n1) {
    arr[k++] = L[i++];
  }

  while (j < n2) {
    arr[k++] = R[j++];
  }
}

void MergeSort::mergeSortRecursive(std::vector<int>& arr, int l, int r, StatisticsCollector& stats) const {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSortRecursive(arr, l, m, stats);
    mergeSortRecursive(arr, m + 1, r, stats);
    merge(arr, l, m, r, stats);
  }
}

void MergeSort::sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const {
  mergeSortRecursive(arr, 0, arr.size() - 1, stats);
}
