#include "ArrayGenerator.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "SortManager.h"
#include "ShellSort.h"
#include "HeapSort.h"

#include <iostream>

using namespace std;

int main() {
  int arraySize = 0;
  // Запрашиваем у пользователя размер массива и количество итераций
  std::cout << "Enter array size: ";
  std::cin >> arraySize;

  SortManager manager;

  // Регистрируем известные сортировки
  manager.registerSorter<BubbleSort>("Bubble Sort");
  manager.registerSorter<InsertionSort>("Insertion Sort");
  manager.registerSorter<QuickSort>("Quick Sort");
  manager.registerSorter<ShellSort>("Shell Sort");
  manager.registerSorter<HeapSort>("Heap Sort");

  // Генерируем случайный массив
  std::vector<int> data = ArrayGenerator::generateRandomArray(arraySize);

  // Запускаем все сортировки
  manager.runAllSorters(data);

  return EXIT_SUCCESS;
}
