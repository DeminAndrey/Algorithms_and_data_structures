#include "task2.h"
#include "task4.h"
#include "tester/tester.h"

#include <iostream>

/*
  Описание параметров командной строки
  ./dynamic <test_path>
  Параметры:
  <test_path>: Путь к папке с тестовыми данными

  Примеры использования:
  ./dynamic C:/dynamic/test1
*/

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Test path not specifed" << std::endl;

    return EXIT_FAILURE;
  }

  Tester tester(argc, argv);
  tester.run_all();

  setlocale(LC_ALL, "ru_RU.UTF-8");

  // Третья задача: Елочка
  std::cout << "\nРешение второй задачи:" << std::endl;
  std::vector<std::vector<int>> tree = {
      {1},
      {2, 3},
      {4, 5, 6}
  };
  new_year_tree(tree);

  // Четвертая задача: Острова в матрице
  std::cout << "\nРешение четвертой задачи:" << std::endl;
  vector<vector<char>> grid = {
      {'1', '0', '1'},
      {'0', '1', '0'},
      {'1', '0', '1'}
  };
  cout << "Количество островов: " << findIslands(grid) << endl;

  return EXIT_SUCCESS;
}
