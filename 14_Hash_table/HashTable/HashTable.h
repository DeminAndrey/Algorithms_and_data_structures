#pragma once

#include <list>
#include <string>
#include <vector>

// Класс узла для хранения элементов в списке
class Node {
public:
  int key;
  std::string value;
  Node* next;

  Node(int k, const std::string& v)
      : key(k), value(v), next(nullptr) {}
};

// Хеш-таблица с использованием метода цепочек
class HashTable {
private:
  static constexpr size_t INITIAL_SIZE = 10; // Начальный размер таблицы
  std::vector<std::list<Node>> m_table;
  size_t m_size; // Текущий размер таблицы
  size_t m_count = 0; // Текущее количество элементов

  // Функция хеширования
  size_t hashFunction(int key) const;

  // Функция рехеширования
  void rehashing();

public:
  explicit HashTable(size_t size = INITIAL_SIZE);

  // Вставка элемента
  void insert(int key, const std::string& value);

  // Поиск элемента по ключу
  bool find(int key, std::string& result) const;

  // Удаление элемента по ключу
  void remove(int key);

  // Печать содержимого хеш-таблицы
  void print() const;
};
