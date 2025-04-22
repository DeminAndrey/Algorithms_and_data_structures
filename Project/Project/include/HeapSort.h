#pragma once

#include "Sorter.h"

class HeapSort : public AbstractSorter {
protected:
  void heapify(std::vector<int>& arr, int n, int rootIndex, StatisticsCollector& stats) const;
  void sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const override;
};
