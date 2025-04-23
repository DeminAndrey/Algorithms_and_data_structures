#include "ArrayGenerator.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "SortManager.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "BucketSort.h"
#include "CountingSort.h"
#include "SelectionSort.h"

#include <iostream>

using namespace std;

int main() {
  int arraySize = 0;
  // Запрашиваем у пользователя размер массива и количество итераций
  std::cout << "Enter array size: ";
  std::cin >> arraySize;

  SortManager manager;

  // Регистрируем известные сортировки
  /*1*/ manager.registerSorter<BubbleSort>("Bubble Sort"); // Пузырьковая
  /*2*/ manager.registerSorter<InsertionSort>("Insertion Sort"); // Вставками
  /*3*/ manager.registerSorter<QuickSort>("Quick Sort"); // Быстрая
  /*4*/ manager.registerSorter<ShellSort>("Shell Sort"); // Шелла
  /*5*/ manager.registerSorter<HeapSort>("Heap Sort"); // Пирамидальная
  /*6*/ manager.registerSorter<MergeSort>("Merge Sort"); // Слиянием
  /*7*/ manager.registerSorter<BucketSort>("Bucket Sort"); // Блочная
  /*8*/ manager.registerSorter<CountingSort>("Counting Sort"); // Подсчётом
  /*9*/ manager.registerSorter<SelectionSort>("Selection Sort"); // Выбором
  /*10*/ //manager.registerSorter<RadixSort>("Radix Sort"); // Поразрядная

  // Генерируем случайный массив
  std::vector<int> data = ArrayGenerator::generateRandomArray(arraySize);

  // Запускаем все сортировки
  manager.runAllSorters(data);

  return EXIT_SUCCESS;
}
