#include "CountingSort.h"

#include <algorithm>

void CountingSort::sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const {
  int maxValue = *std::max_element(arr.begin(), arr.end());
  int minValue = *std::min_element(arr.begin(), arr.end());
  int range = maxValue - minValue + 1;

  // Создаем массив для подсчета частот
  std::vector<int> counts(range, 0);

  // Подсчет частоты каждого элемента
  for (int value : arr) {
    counts[value - minValue]++;
    stats.incrementComparisons();
  }

  // Пересчитываем накопленные суммы
  for (int i = 1; i < range; i++) {
    counts[i] += counts[i - 1];
  }

  // Формируем отсортированный массив
  std::vector<int> output(arr.size());
  for (int i = arr.size() - 1; i >= 0; i--) {
    int value = arr[i];
    output[counts[value - minValue] - 1] = value;
    counts[value - minValue]--;
  }

  // Возвращаем отсортированный массив
  arr.assign(output.begin(), output.end());
}
