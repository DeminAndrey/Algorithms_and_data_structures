#include "HashTable.h"

#include <iostream>

int main() {
  HashTable ht(5); // Создаем таблицу размером 5

  // Вставляем элементы
  ht.insert(1, "Earth");
  ht.insert(6, "Pluton");
  ht.insert(11, "Jupiter");
  ht.insert(16, "Date");
  ht.insert(21, "Mars");

  ht.print();

  // Ищем элемент 11
  std::string result;
  if (ht.find(11, result)) {
    std::cout << "Found: " << result << "\n";
  }
  else {
    std::cout << "Not found.\n";
  }

  std::cout << std::endl;

  // Удаляем элемент
  ht.remove(11);

  ht.print();

  return EXIT_SUCCESS;
}
