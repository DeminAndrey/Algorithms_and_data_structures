#include "Sorter.h"

void AbstractSorter::sort(std::vector<int>& arr, Stats& output_stats) const {
  StatisticsCollector collector;
  collector.startTimer();
  this->sortImpl(arr, collector);
  output_stats = collector.stopAndGetStats();
}
