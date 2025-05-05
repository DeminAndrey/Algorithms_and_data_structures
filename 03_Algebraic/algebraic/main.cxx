#include "alg.h"

#include <cassert>
#include <functional>
#include <iostream>


void fib_run(std::function<size_t(size_t)> f) {
  int n = 1;
  std::cout << "Введите порядковый номер числа Фибоначчи, или 0 для выхода: \n";
  while (n) {
    std::cin >> n;
    if (n == 0)
      break;

    std::cout << "Число Фибоначчи номер " << n << " равно = " << f(n) << std::endl;
  }
}

void simple_run(std::function<size_t(size_t)> f) {
  int n = 1;
  std::cout << "Введите целое положительное число, или 0 для выхода: \n";
  while (n) {
    std::cin >> n;
    if (n == 0)
      break;

    std::cout << "Количество простых чисел в диапазоне от 2 до числа "
              << n << " равно = " << f(n) << std::endl;
  }
}

int main() {
  // возведение в степень
  const int num = 2;
  for (int r : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
    assert(alg::pow(num, r) == std::pow(num, r));

  // нахождение числа Фибоначчи
  // рекурсивный способ
  setlocale(LC_ALL, "ru_RU.UTF-8");
  fib_run(alg::fib_recursive);
  // итерационный
  fib_run(alg::fib_iter);

  // простые числа
  simple_run(alg::simple_num_counter);

  return 0;
}
