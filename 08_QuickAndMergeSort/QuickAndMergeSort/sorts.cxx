#include "sorts.h"

#include <algorithm>

using namespace std;

namespace sorts {
// Функция для разделения вектора на части относительно опорного элемента
pair<vector<int>, vector<int>> partition(
    const vector<int> &vec, int low, int high) {
  vector<int> temp_vec(vec.begin() + low, vec.begin() + high + 1); // Копируем часть вектора в новый вектор

  int pivot = temp_vec[(high - low) / 2];
  int i = low, j = high;

  while (i <= j) {
    while (temp_vec[i] < pivot) {
      ++i;
    }
    while (temp_vec[j] > pivot) {
      --j;
    }
    if (i <= j) {
      swap(temp_vec[i], temp_vec[j]);
      ++i;
      --j;
    }
  }
  // Возвращаем разделенные части вектора
  return { vector<int>(temp_vec.begin(), temp_vec.begin() + i - low),
           vector<int>(temp_vec.begin() + i - low, temp_vec.end()) };}

// Рекурсивная функция быстрой сортировки
void quickSortRecursive(vector<int> &vec, int low, int high) {
  if (low >= high) {
    return;
  }

  auto parts = partition(vec, low, high);
  quickSortRecursive(
      parts.first, low, static_cast<int>(parts.first.size() - 1));
  quickSortRecursive(
      parts.second, 0, static_cast<int>(parts.second.size() - 1));
}

// Основная функция быстрой сортировки
void quickSort(vector<int> &values) {
  quickSortRecursive(values, 0, static_cast<int>(values.size() - 1));
}

// Вспомогательная функция для слияния двух отсортированных частей вектора
vector<int> merge(const vector<int> &left,
                       const vector<int> & right) {
  vector<int> result;
  int i = 0, j = 0;

  while (i < left.size() && j < right.size()) {
    if (left[i] <= right[j]) {
      result.push_back(left[i++]);
    } else {
      result.push_back(right[j++]);
    }
  }

  // Добавляем оставшиеся элементы из левого или правого вектора
  while (i < left.size()) {
    result.push_back(left[i++]);
  }
  while (j < right.size()) {
    result.push_back(right[j++]);
  }

  return result;
}

// Рекурсивная функция сортировки слиянием
vector<int> mergeSort(const vector<int> &values) {
  if (values.size() <= 1) {
    return values;
  }
  int mid = values.size() / 2;
  vector<int> left(values.begin(), values.begin() + mid);
  vector<int> right(values.begin() + mid, values.end());

  return merge(mergeSort(left), mergeSort(right));
}
} // namespace sorts
