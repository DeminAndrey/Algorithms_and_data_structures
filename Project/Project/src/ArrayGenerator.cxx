#include "ArrayGenerator.h"

#include <random>

std::vector<int> ArrayGenerator::generateRandomArray(int size) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(-1000, 1000); // генерируем числа от -1000 до +1000

  std::vector<int> array(size);
  for (auto& elem : array) {
    elem = dis(gen);
  }
  return array;
}
