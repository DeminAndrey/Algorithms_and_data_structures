#pragma once

#include <vector>

namespace sorts {
// Основная функция быстрой сортировки
void quickSort(std::vector<int> &values);

// Рекурсивная функция сортировки слиянием
std::vector<int> mergeSort(const std::vector<int> &values);
} // namespace sorts
