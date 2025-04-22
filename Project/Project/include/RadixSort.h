#pragma once

#include "Sorter.h"

class RadixSort : public AbstractSorter {
protected:
  void countingSortByDigit(std::vector<int>& arr, int exp, StatisticsCollector& stats) const;
  void sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const override;
};
