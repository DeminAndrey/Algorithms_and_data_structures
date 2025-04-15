#include "tester/tester.hpp"

/*
  Описание параметров командной строки
  ./dynamic <test_path>
  Параметры:
  <test_path>: Путь к папке с тестовыми данными

  Примеры использования:
  ./dynamic C:/dynamic/test1
*/

int main(int argc, char** argv) {
  Tester tester(argc, argv);
  tester.run_all();

  return EXIT_SUCCESS;
}
