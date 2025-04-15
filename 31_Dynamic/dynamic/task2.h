#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int numbers_from_5_and_8(int N) {
  vector<vector<int>> tree(N); // Ёлка
  vector<int> dp(N);           // Массив для хранения максимальных сумм

  // Чтение дерева
  for (int i = 0; i < N; ++i) {
    string line;
    getline(cin, line); // Пропускаем пустые строки после ввода высоты
    istringstream iss(line);

    while (iss.good()) {
      int digit;
      iss >> digit;
      tree[i].push_back(digit);
    }
  }

  // Инициализация первого уровня
  dp[0] = tree[0][0];

  // Обработка остальных уровней
  for (int level = 1; level < N; ++level) {
    for (size_t pos = 0; pos <= level; ++pos) {
      if (pos == 0) { // Левый край
        dp[pos] = max(dp[pos], dp[pos - 1]) + tree[level][pos];
      } else if (pos == level) { // Правый край
        dp[pos] = max(dp[pos], dp[pos - 1]) + tree[level][pos];
      } else { // Промежуточные позиции
        dp[pos] = max(dp[pos], max(dp[pos - 1], dp[pos])) + tree[level][pos];
      }
    }
  }

  // Ответ — максимальная сумма в последнем уровне
  int max_sum = 0;
  for (int i = 0; i < N; ++i) {
    max_sum = max(max_sum, dp[i]);
  }

  return max_sum;
}
