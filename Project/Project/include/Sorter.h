#pragma once

#include "Statistics.h"

#include <vector>

class AbstractSorter {
// public:
//   virtual ~AbstractSorter() = 0;
protected:
  virtual void sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const = 0;

public:
  void sort(std::vector<int>& arr, Stats& output_stats) const;
};
