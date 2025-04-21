#pragma once

#include <chrono>

struct Stats {
  int comparisons;
  int swaps;
  long long duration_ms;
};

class StatisticsCollector {
private:
  std::chrono::high_resolution_clock::time_point startTime;
  int comparisons;
  int swaps;

public:
  void startTimer();
  Stats stopAndGetStats();
  void incrementComparisons();
  void incrementSwaps();
};
