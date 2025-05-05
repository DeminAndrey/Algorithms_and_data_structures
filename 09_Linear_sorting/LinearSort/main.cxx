#include "sorts.h"

#include <iostream>

#include <ctime>
#include <cstdlib>

using namespace std;

constexpr int MAX_VALUE = 1000;

// Функция для генерации случайного вектора
vector<int> generateRandomVector(int size) {
  vector<int> vec(static_cast<size_t>(size));
  for (int& val : vec) {
    val = rand() % MAX_VALUE;  // случайное число от 0 до 999
  }
  return vec;
}

// Шаблонная функция для запуска алгоритма сортировки с подсчетом времени выполнения
template <typename Func, typename... Args>
double run(Func &&f, vector<int> &values, Args&&... args) {
  clock_t startTime = clock(); // Начало измерения времени
  f(values, std::forward<Args>(args)...); // Сортировка вектора
  clock_t endTime = clock(); // Конец измерения времени

  double timeTaken =
      static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC; // Время выполнения в секундах

  return timeTaken;
}

// Функция для тестирования и замера времени выполнения
void testSortingAlgorithms() {
  int sizes[] = {100, 1000, 10000, 100000, 1000000};

  cout << "Testing Sorting Algorithms\n";
  cout << "Size\tCounting Sort\tRadix Sort\tBucket Sort\n";

  srand(static_cast<unsigned int>(time(nullptr)));  // Инициализация генератора случайных чисел

  for (int size : sizes) {
    // Тестирование Counting Sort
    vector<int> vec = generateRandomVector(size);
    double countingTime = run(sorts::countingSort, vec, MAX_VALUE);

    // Тестирование Radix Sort
    vec = generateRandomVector(size);
    double radixTime = run(sorts::radixSort, vec, 10);

    // Тестирование Bucket Sort
    vec = generateRandomVector(size);
    double bucketTime = run(sorts::bucketSort, vec);

    // Вывод результатов
    cout << size << "\t" << countingTime << "\t\t"
         << radixTime << "\t\t" << bucketTime << "\n";
  }
}

int main() {
  testSortingAlgorithms();
  return 0;
}
