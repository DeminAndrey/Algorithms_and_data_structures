#pragma once

#include <vector>

namespace sorts {
/**
 * @brief Реализация алгоритма сортировки подсчётами (Counting Sort)
 * @param values входной контейнер элементов для сортировки
 * @param maxVal максимальное значение элемента во входном наборе
 */
void countingSort(std::vector<int>& values, int maxVal);

/**
 * @brief Реализация алгоритма поразрядной сортировки (Radix Sort)
 * @param values входной контейнер элементов для сортировки
 * @param base основание для сортировки, по умолчанию 10
 */
void radixSort(std::vector<int>& values, int base = 10);

/**
 * @brief Реализация алгоритма блочной сортировки (Bucket Sort)
 * @param values входной контейнер элементов для сортировки
 */
void bucketSort(std::vector<int>& values);
} // namespace sorts
