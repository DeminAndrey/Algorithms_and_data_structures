#pragma once

#include "Sorter.h"

class InsertionSort : public AbstractSorter {
protected:
  void sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const override;
};
