#pragma once

#include "Sorter.h"

class BubbleSort final : public AbstractSorter {
// public:
//   ~BubbleSort() override {}
protected:
  void sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const override;
};
