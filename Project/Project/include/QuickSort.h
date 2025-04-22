#pragma once

#include "Sorter.h"

class QuickSort : public AbstractSorter {
protected:
  void quickSortHelper(std::vector<int>& arr, int low, int high, StatisticsCollector& stats) const;
  int partition(std::vector<int>& arr, int low, int high, StatisticsCollector& stats) const;
  void sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const override;
};
