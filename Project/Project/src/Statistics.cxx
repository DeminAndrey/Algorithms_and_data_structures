#include "Statistics.h"

void StatisticsCollector::startTimer() {
  startTime = std::chrono::high_resolution_clock::now();
  comparisons = 0;
  swaps = 0;
}

Stats StatisticsCollector::stopAndGetStats() {
  auto endTime = std::chrono::high_resolution_clock::now();
  auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
  return {comparisons, swaps, elapsedMs};
}

void StatisticsCollector::incrementComparisons() {
  ++comparisons;
}

void StatisticsCollector::incrementSwaps() {
  ++swaps;
}
