#pragma once

#include <stdexcept>

namespace alg {
/**
 * @brief pow Итеративный O(N) алгоритм возведения
 *  числа в степень (положительная)
 * @param num число
 * @param range степень(положительная)
 * @return результат вычисления
 */
template <typename T>
T pow(T num, int range) {
  if (range == 1)
    return num;
  T res = 1;
  for (int i = 1; i <= range; ++i)
    res *= num;
  return res;
}

/**
 * @brief fib Рекурсивный (2^N) способ нахождения числа Фибоначчи
 * @param num порядковый номер числа Фибоначчи (положительное число > 0)
 * @return число Фибоначчи
 */
size_t fib_recursive(size_t num) {
  if (num == 0)
    throw std::invalid_argument("argument cannot be zero!");
  if (num == 1 || num == 2)
    return 1;
  return fib_recursive(num - 1) + fib_recursive(num - 2);
}

/**
 * @brief fib_iter Итеративный (N^2) способ нахождения числа Фибоначчи
 * @param num порядковый номер числа Фибоначчи (положительное число > 0)
 * @return число Фибоначчи
 */
size_t fib_iter(size_t num) {
  size_t prev = 1;
  size_t next = 1;
  for (size_t i = 2; i < num; ++i) {
    size_t res = prev + next;
    prev = next;
    next = res;
  }
  return next;
}

/**
 * @brief is_simple
 * @param n
 * @return
 */
bool is_simple(int n) {
  int count = 0;
  for(int i = 1; i <= n; ++i)
    if (n % i == 0)
      count++;

  return (count == 2) ? true : false;
}

/**
 * @brief simple_num_counter
 * @param num
 * @return
 */
int simple_num_counter(int num) {
  int count = 0;
  for(int i = 2; i <= num; i++)
    if (alg::is_simple(i))
      count++;

  return count;
}
} // namespace alg
