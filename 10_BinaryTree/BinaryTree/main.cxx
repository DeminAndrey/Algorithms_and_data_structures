#include "BinarySearchTree.h"

#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
using namespace chrono;

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  BinarySearchTree balancedTree;     // Дерево с элементами в случайном порядке
  BinarySearchTree unbalancedTree;   // Дерево с элементами в возрастающем порядке

  const int N = 10000;              // Максимальный размер дерева
  vector<int> randomNumbers(N);      // Последовательность случайных чисел
  for (int i = 0; i < N; ++i) {
    randomNumbers[i] = rand() % N + 1; // Числа от 1 до N
  }

  setlocale(LC_ALL, "ru_RU.UTF-8");

  // Замер времени вставки в сбалансированное дерево
  auto startTime = high_resolution_clock::now();
  for (auto num : randomNumbers) {
    balancedTree.insert(num);
  }
  auto endTime = high_resolution_clock::now();
  double insertionTimeBalancedTree = duration_cast<milliseconds>(endTime - startTime).count();
  cout << "Время вставки в сбалансированное дерево: " << insertionTimeBalancedTree << " мс" << endl;

  // Замер времени вставки в несбалансированное дерево
  startTime = high_resolution_clock::now();
  vector<int> sortedNumbers(randomNumbers.begin(), randomNumbers.end());
  sort(sortedNumbers.begin(), sortedNumbers.end());  // Отсортируем последовательность
  for (auto num : sortedNumbers) {
    unbalancedTree.insert(num);
  }
  endTime = high_resolution_clock::now();
  double insertionTimeUnbalancedTree = duration_cast<milliseconds>(endTime - startTime).count();
  cout << "Время вставки в несбалансированное дерево: " << insertionTimeUnbalancedTree << " мс" << endl;

  // Генерация случайных чисел для поиска и удаления
  vector<int> searchNumbers(N / 10);
  generate(searchNumbers.begin(), searchNumbers.end(), [N]() { return rand() % N + 1; });

  // Замер времени поиска в сбалансированном дереве
  startTime = high_resolution_clock::now();
  for (auto num : searchNumbers) {
    balancedTree.search(num);
  }
  endTime = high_resolution_clock::now();
  double searchTimeBalancedTree = duration_cast<milliseconds>(endTime - startTime).count();
  cout << "Время поиска в сбалансированном дереве: " << searchTimeBalancedTree << " мс" << endl;

  // Замер времени поиска в несбалансированном дереве
  startTime = high_resolution_clock::now();
  for (auto num : searchNumbers) {
    unbalancedTree.search(num);
  }
  endTime = high_resolution_clock::now();
  double searchTimeUnbalancedTree = duration_cast<milliseconds>(endTime - startTime).count();
  cout << "Время поиска в несбалансированном дереве: " << searchTimeUnbalancedTree << " мс" << endl;

  // Замер времени удаления в сбалансированном дереве
  startTime = high_resolution_clock::now();
  for (auto num : searchNumbers) {
    balancedTree.remove(num);
  }
  endTime = high_resolution_clock::now();
  double removalTimeBalancedTree = duration_cast<milliseconds>(endTime - startTime).count();
  cout << "Время удаления в сбалансированном дереве: " << removalTimeBalancedTree << " мс" << endl;

  // Замер времени удаления в несбалансированном дереве
  startTime = high_resolution_clock::now();
  for (auto num : searchNumbers) {
    unbalancedTree.remove(num);
  }
  endTime = high_resolution_clock::now();
  double removalTimeUnbalancedTree = duration_cast<milliseconds>(endTime - startTime).count();
  cout << "Время удаления в несбалансированном дереве: " << removalTimeUnbalancedTree << " мс" << endl;

  return 0;
}
