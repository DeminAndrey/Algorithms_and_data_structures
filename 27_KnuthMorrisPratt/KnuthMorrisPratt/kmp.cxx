#include "kmp.h"

#include <iostream>

// Медленное вычисление префикс-функции
std::vector<int> prefix_function_naive(const std::string& pattern) {
  int n = pattern.size();
  std::vector<int> pi(n, 0); // Префикс-функция

  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && pattern[i] != pattern[j]) {
      j = pi[j - 1];
    }
    if (pattern[i] == pattern[j]) {
      ++j;
    }
    pi[i] = j;
  }
  return pi;
}

// Быстрое вычисление префикс-функции
std::vector<int> prefix_function_fast(const std::string& pattern) {
  int n = pattern.size();
  std::vector<int> pi(n, 0); // Префикс-функция

  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && pattern[i] != pattern[j]) {
      j = pi[j - 1];
    }
    if (pattern[i] == pattern[j]) {
      ++j;
    }
    pi[i] = j;
  }
  return pi;
}

// Алгоритм Кнут-Мориса-Пратта
void knuth_morris_pratt(const std::string& text, const std::string& pattern) {
  auto pi = prefix_function_fast(pattern);
  int m = pattern.size();
  int n = text.size();
  int q = 0; // Кол-во совпадений

  for (int i = 0; i < n; ++i) {
    while (q > 0 && pattern[q] != text[i]) {
      q = pi[q - 1]; // Переход по префикс-функции
    }
    if (pattern[q] == text[i]) {
      ++q;
    }
    if (q == m) { // Нашли шаблон
      std::cout << "Found pattern at index: " << i - m + 1 << '\n';
      q = pi[q - 1]; // Продолжаем искать другие вхождения
    }
  }
}
