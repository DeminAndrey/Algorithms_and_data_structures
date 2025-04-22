#include "RadixSort.h"

#include <algorithm>

void RadixSort::countingSortByDigit(std::vector<int>& arr, int exp, StatisticsCollector& stats) const {
  int n = arr.size();
  std::vector<int> output(n);
  std::vector<int> count(10, 0);

  // Подсчет частот появления каждой цифры
  for (int i = 0; i < n; i++) {
    int digit = (arr[i] / exp) % 10;
    count[digit]++;
  }

  // Накопленная сумма частоты
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  // Копируем элементы в выходной массив
  for (int i = n - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;
    output[count[digit] - 1] = arr[i];
    count[digit]--;
  }

  // Возвращаем отсортированный массив
  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

void RadixSort::sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const {
  int maxElement = *std::max_element(arr.begin(), arr.end());

  // Находим максимальное количество разрядов
  int exp = 1;
  while (maxElement / exp > 0) {
    countingSortByDigit(arr, exp, stats);
    exp *= 10;
  }
}
