#include "sorts.h"

#include <iostream>
#include <ctime>
#include <functional>

using namespace std;

// Функция для генерации случайного вектора заданного размера
vector<int> generateRandomVector(size_t size) {
  vector<int> vec(size);
  srand(static_cast<unsigned int>(time(nullptr))); // Инициализируем генератор случайных чисел
  for (size_t i = 0; i < size; ++i) {
    vec[i] = rand() % 1000; // Генерация случайных чисел от 0 до 999
  }
  return vec;
}

void run(function<void(vector<int> &values)> &&f,
         vector<int> &values) {
  clock_t startTime = clock(); // Начало измерения времени
  f(values); // Сортировка вектора
  clock_t endTime = clock(); // Конец измерения времени

  double timeTaken =
      static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC; // Время выполнения в секундах

  cout << "Время выполнения: " << timeTaken << " секунд." << endl;
}

int main() {
  int sizes[] = {100, 1000, 10000, 100000}; // Массив размеров

  setlocale(LC_ALL, "ru_RU.UTF-8");

  for (int size : sizes) {
    // Генерация случайного вектора
    vector<int> randomVec = generateRandomVector(size);

    // Копирование вектора для двух типов сортировок
    vector<int> selectionVec(randomVec.begin(), randomVec.end());
    vector<int> heapVec(randomVec.begin(), randomVec.end());

    cout << "Вектор размером " << size << " элементов" << endl;

    cout << "Сортировка выбором (Selection Sort):\n";
    run(sorts::selectionSort, selectionVec);

    cout << "Пирамидальная сортировка (Heap Sort):\n";
    run(sorts::heapSort, heapVec);

    cout << endl;
  }

  return 0;
}
