#include "sorts.h"

#include <iostream>
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

void run(std::function<void(vector<int> &values)> &&f,
         vector<int> &values) {
  clock_t startTime = clock(); // Начало измерения времени
  f(values); // Сортировка вектора
  clock_t endTime = clock(); // Конец измерения времени

  double timeTaken =
      static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC; // Время выполнения в секундах

  cout << "Время выполнения: " << timeTaken << " секунд." << endl;
}

int main() {
  int sizes[] = {100, 1000, 10000}; // Массив размеров

  setlocale(LC_ALL, "ru_RU.UTF-8");

  for (int size : sizes) {
    // Генерация случайного вектора
    std::vector<int> randomVec = generateRandomVector(size);

    // Копирование вектора для трех типов сортировок
    vector<int> bubbleVec(randomVec.begin(), randomVec.end());
    vector<int> insertionVec(randomVec.begin(), randomVec.end());
    vector<int> shellVec(randomVec.begin(), randomVec.end());

    cout << "Вектор размером " << size << " элементов" << endl;

    cout << "Пузырькова сортировка (Bubble sort):\n";
    run(simple_sorts::bubbleSort, bubbleVec);

    cout << "Сортировка вставками (Insertion sort):\n";
    run(simple_sorts::insertionSort, insertionVec);

    cout << "Сортировка Шелла (Shell sort):\n";
    run(simple_sorts::shellSort, shellVec);

    cout << endl;
  }

  return 0;
}
