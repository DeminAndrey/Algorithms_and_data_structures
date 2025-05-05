#include "sorts.h"

#include <algorithm>

using namespace std;

void sorts::countingSort(vector<int>& values, int maxVal) {
  const int n = values.size();
  vector<int> count(maxVal + 1, 0);  // счётчик частоты появления каждого числа

  // Подсчитать частоту каждого числа
  for (int i = 0; i < n; ++i) {
    count[values[i]]++;
  }

  // Перестроим count[], чтобы каждый элемент содержал
  // позицию последнего элемента в отсортированном массиве
  for (int i = 1; i <= maxVal; ++i) {
    count[i] += count[i - 1];
  }

  // Создаём временный массив для хранения результата
  vector<int> output(n);

  // Заполнение выходного массива
  for (int i = n - 1; i >= 0; --i) {
    output[count[values[i]] - 1] = values[i];
    count[values[i]]--;
  }

  // Копируем отсортированные данные обратно в исходный вектор
  for (int i = 0; i < n; ++i) {
    values[i] = output[i];
  }
}

void sorts::radixSort(vector<int>& values, int base) {
  int n = values.size();
  int maxNum = *max_element(values.begin(), values.end());

  // Проходимся по разрядам числа
  for (int exp = 1; maxNum / exp > 0; exp *= base) {
    vector<vector<int>> buckets(base);

    // Распределение элементов по корзинам
    for (int i = 0; i < n; ++i) {
      int digit = (values[i] / exp) % base;
      buckets[digit].push_back(values[i]);
    }

    // Объединяем содержимое всех корзин обратно в исходный массив
    int idx = 0;
    for (auto& bucket : buckets) {
      for (int num : bucket) {
        values[idx++] = num;
      }
    }
  }
}

void sorts::bucketSort(vector<int>& values) {
  int n = values.size();
  if (n <= 0) return;  // Проверка на пустой массив

  double minVal = *min_element(values.begin(), values.end());  // Минимальный элемент
  double maxVal = *max_element(values.begin(), values.end());  // Максимальный элемент

  // Вычисление размера блока
  double intervalSize = (maxVal - minVal) / n + 1;

  // Создание блоков
  vector<vector<double>> buckets(n);

  // Распределение элементов массива по блокам
  for (size_t i = 0; i < n; ++i) {
    size_t idx = static_cast<size_t>((values[i] - minVal) / intervalSize);
    buckets[idx].push_back(values[i]);
  }

  // Сортировка элементов в каждом блоке
  for (auto& bucket : buckets) {
    sort(bucket.begin(), bucket.end());
  }

  // Объединение отсортированных блоков обратно в исходный массив
  size_t index = 0;
  for (const auto& bucket : buckets) {
    for (double num : bucket) {
      values[index++] = num;
    }
  }
}
