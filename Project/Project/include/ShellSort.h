#pragma once

#include "Sorter.h"

class ShellSort : public AbstractSorter {
protected:
  void shellSortImpl(std::vector<int>& arr, StatisticsCollector& stats) const;
  void sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const override;
};
