#pragma once

#include "Sorter.h"

class MergeSort : public AbstractSorter {
protected:
  void merge(std::vector<int>& arr, int l, int m, int r, StatisticsCollector& stats) const;
  void mergeSortRecursive(std::vector<int>& arr, int l, int r, StatisticsCollector& stats) const;
  void sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const override;
};
