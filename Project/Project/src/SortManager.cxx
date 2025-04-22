#include "SortManager.h"
#include "Statistics.h"

#include <iostream>
#include <future>

void SortManager::runAllSorters(const std::vector<int>& inputData) {
  std::map<std::string, Stats> aggregatedStats;

  std::vector<std::future<void>> futures;

  for (auto &[name, sorter]  : m_sorters) {
    futures.emplace_back(std::async(std::launch::async, [&]() {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::vector<int> copy(inputData.begin(), inputData.end());
        Stats results;
        sorter->sort(copy, results);

        // Аграгируем статистику
        aggregatedStats[name] = results;
      })
    );
  }

  // Ждём завершения всех задач
  for (auto& f : futures) {
    f.wait();
  }

  printComparisonTable(aggregatedStats);
}


// Функция красивого вывода таблицы статистики
void SortManager::printComparisonTable(const std::map<std::string, Stats> &aggregatedStats) const {
  std::cout << "+----------------------+------------------+-------------+------------+" << std::endl;
  std::cout << "| Algorithm            | Duration (ms)    | Comparisons | Swaps      |" << std::endl;
  std::cout << "+----------------------+------------------+-------------+------------+" << std::endl;

  for (const auto &[name, stats] : aggregatedStats) {
    printf("| %-20s | %16.2ld | %11d | %10d |\n",
           name.c_str(), stats.duration_ms, stats.comparisons, stats.swaps);
  }

  std::cout << "+----------------------+------------------+-------------+------------+" << std::endl;
}

