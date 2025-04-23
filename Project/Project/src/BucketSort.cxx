#include "BucketSort.h"

#include <algorithm>

void BucketSort::bucketSortInternal(std::vector<int>& arr, int bucketsCount, StatisticsCollector& stats) const {
  int minVal = *std::min_element(arr.begin(), arr.end());
  int maxVal = *std::max_element(arr.begin(), arr.end());
  float range = ((float)(maxVal - minVal)) / bucketsCount;

  std::vector<std::vector<int>> buckets(bucketsCount);

  // Распределение элементов по корзинам
  for (int val : arr) {
    int index = std::floor((val - minVal) / range);
    if (index == bucketsCount) index--;
    buckets[index].push_back(val);
  }

  // Сортируем каждую корзину и объединяем
  int idx = 0;
  for (auto& bucket : buckets) {
    std::sort(bucket.begin(), bucket.end());
    for (int val : bucket) {
      arr[idx++] = val;
    }
  }
}

void BucketSort::sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const {
  bucketSortInternal(arr, 10, stats); // 10 корзин по умолчанию
}
