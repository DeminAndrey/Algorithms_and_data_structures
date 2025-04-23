#pragma once

#include "Sorter.h"

class SelectionSort : public AbstractSorter {
protected:
  void sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const override;
};
