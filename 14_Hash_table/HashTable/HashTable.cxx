#include "HashTable.h"

#include <iostream>

using namespace std;

HashTable::HashTable(size_t size)
    : m_table(size), m_size(size) {}

size_t HashTable::hashFunction(int key) const {
  return key % m_size;
}

// Функция для вычисления нового размера таблицы
size_t rehash(size_t current_size) {
  return current_size * 2;
}

void HashTable::rehashing() {
  size_t newSize = rehash(m_size);
  std::vector<std::list<Node>> newTable(newSize);

  for (const auto& chain : m_table) {
    for (const Node& node : chain) {
      size_t newIndex = node.key % newSize;
      newTable[newIndex].emplace_back(node.key, node.value);
    }
  }

  m_table = std::move(newTable);
  m_size = newSize;
}

void HashTable::insert(int key, const std::string& value) {
  size_t index = hashFunction(key);
  auto& chain = m_table[index];
  for (auto& node : chain) {
    if (node.key == key) {
      node.value = value;
      return;
    }
  }
  chain.emplace_back(key, value);
  ++m_count;

  // Проверяем, нужно ли делать рехэширование
  if ((static_cast<double>(m_count) / m_size) > 0.75) {
    rehashing();
  }
}

bool HashTable::find(int key, string& result) const {
  size_t index = hashFunction(key);
  for (const auto& node : m_table[index]) {
    if (node.key == key) {
      result = node.value;
      return true;
    }
  }
  return false;
}

void HashTable::remove(int key) {
  size_t index = hashFunction(key);
  auto& chain = m_table[index];
  for (auto it = chain.begin(); it != chain.end(); ++it) {
    if (it->key == key) {
      it = chain.erase(it); // Удаляем узел
      --m_count;
      return;
    }
  }
}

void HashTable::print() const {
  for (size_t i = 0; i < m_size; ++i) {
    cout << "Bucket " << i << ": ";
    for (const auto& node : m_table[i]) {
      cout << "(" << node.key << ", " << node.value << ") -> ";
    }
    cout << "NULL\n";
  }
  std::cout << std::endl;
}
