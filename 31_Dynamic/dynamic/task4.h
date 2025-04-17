#pragma once

#include <vector>

using namespace std;

// Функция для поиска островов с использованием DFS
void dfs(vector<vector<char>>& grid, int x, int y) {
  // Проверка выхода за границы и проверки на 0 или уже посещенное
  if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1') {
    return;
  }
  // Помечаем клетку как посещенную
  grid[x][y] = '#';
  // Рекурсивно проходим по соседям
  dfs(grid, x + 1, y);  // Вниз
  dfs(grid, x - 1, y);  // Вверх
  dfs(grid, x, y + 1);  // Вправо
  dfs(grid, x, y - 1);  // Влево
}

// Основная функция для подсчета островов
int findIslands(vector<vector<char>>& grid) {
  int islandsCount = 0;
  // Проходим по всей матрице
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      if (grid[i][j] == '1') {  // Нашли остров
        islandsCount++;
        dfs(grid, i, j);  // Посещаем весь остров
      }
    }
  }
  return islandsCount;
}
