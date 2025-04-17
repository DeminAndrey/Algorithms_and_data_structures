#include <algorithm>
#include <iostream>
#include <vector>

// Функция для нахождения максимальной суммы гирлянды
void new_year_tree(const std::vector<std::vector<int>>& tree) {
  int N = static_cast<int>(tree.size()); // Высоту получаем автоматически из дерева

  // Таблица динамического программирования
  std::vector<std::vector<int>> dp(N, std::vector<int>(N));

  // Верхушка ёлочки
  dp[0][0] = tree[0][0];

  // Динамическая обработка дерева
  for (int level = 1; level < N; ++level) {
    for (int pos = 0; pos <= level; ++pos) {
      // Либо идём сверху слева, либо сверху справа
      int leftParent = (pos > 0) ? dp[level - 1][pos - 1] : INT_MIN;
      int rightParent = (pos < level) ? dp[level - 1][pos] : INT_MIN;

      // Берём лучшее направление и добавляем текущее значение
      dp[level][pos] = std::max(leftParent, rightParent) + tree[level][pos];
    }
  }

  // Находим максимальную сумму на последнем уровне
  int maxSum = 0;
  for (int i = 0; i < N; ++i) {
    maxSum = std::max(maxSum, dp[N - 1][i]);
  }

  std::cout << "Максимальная сумма гирлянды: " << maxSum << std::endl;
}
