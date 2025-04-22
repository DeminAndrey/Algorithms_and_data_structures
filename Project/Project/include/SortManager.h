#pragma once

#include "Sorter.h"

#include <map>
#include <memory>
#include <string>
#include <vector>
#include <mutex>

class SortManager {
private:
  std::map<std::string, std::shared_ptr<AbstractSorter>> m_sorters;
  mutable std::mutex m_mutex;

public:
  // Регистрация нового сортировщика
  template<typename T>
  void registerSorter(const std::string& name) {
    m_sorters[name] = std::make_shared<T>();
  }

  // Запуск всех зарегистрированных сортеров
  void runAllSorters(const std::vector<int>& inputData);

  // Вывод сводной статистики
  void printComparisonTable(const std::map<std::string, Stats> &aggregatedStats) const;
};
