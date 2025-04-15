#pragma once

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

void islands_in_matrix() {
  int N;
  cin >> N;

  // dp[n][last_digit][count]
  vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(2, vector<long long>(3)));

  // Базовые случаи для n = 1
  dp[1][0][0] = 1; // последняя цифра 5, нет повторений
  dp[1][1][0] = 1; // последняя цифра 8, нет повторений

  for (int n = 2; n <= N; ++n) {
    // Перебираем последнюю цифру
    for (int last_digit = 0; last_digit <= 1; ++last_digit) {
      int prev_digit = 1 - last_digit; // другая цифра (если last_digit=0, то prev_digit=1)

      // Перебираем количество последовательных цифр
      for (int count = 0; count <= 2; ++count) {
        if (count == 2) {
          // Нельзя иметь три одинаковые цифры подряд
          continue;
        }

        // Добавляем новую цифру
        dp[n][prev_digit][0] += dp[n - 1][last_digit][count]; // добавляем другую цифру
        dp[n][last_digit][min(count + 1, 2)] += dp[n - 1][last_digit][count]; // добавляем такую же цифру
      }
    }
  }

  // Суммируем все допустимые варианты для длины N
  long long result = 0;
  for (int last_digit = 0; last_digit <= 1; ++last_digit) {
    for (int count = 0; count <= 2; ++count) {
      result += dp[N][last_digit][count];
    }
  }

  cout << result % MOD << endl;
}
