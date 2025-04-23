#pragma once

#include "Sorter.h"

class BucketSort : public AbstractSorter {
protected:
  void bucketSortInternal(std::vector<int>& arr, int bucketsCount, StatisticsCollector& stats) const;
  void sortImpl(std::vector<int>& arr, StatisticsCollector& stats) const override;
};
