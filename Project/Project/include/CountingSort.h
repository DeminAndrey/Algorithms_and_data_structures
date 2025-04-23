#pragma once

#include "Sorter.h"

class CountingSort : public AbstractSorter {
protected:
  void sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const override;
};
