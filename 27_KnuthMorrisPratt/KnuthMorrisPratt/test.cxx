#include "kmp.h"

#include <chrono>
#include <iostream>

void test_kmp() {
  std::string text = "abcxabcdabcdabcy";
  std::string pattern = "abcdabcy";

  std::cout << "Testing KMP algorithm:\n";
  knuth_morris_pratt(text, pattern);
}

void benchmark_prefix_functions(int T) {
  std::string pattern = "abracadabra";

  auto start_time = std::chrono::steady_clock::now();
  for (int t = 0; t < T; ++t) {
    prefix_function_naive(pattern);
  }
  auto end_time = std::chrono::steady_clock::now();
  double naive_time = std::chrono::duration<double>(end_time - start_time).count();

  start_time = std::chrono::steady_clock::now();
  for (int t = 0; t < T; ++t) {
    prefix_function_fast(pattern);
  }
  end_time = std::chrono::steady_clock::now();
  double fast_time = std::chrono::duration<double>(end_time - start_time).count();

  std::cout << "Naive time: " << naive_time / T << " s\n";
  std::cout << "Fast time: " << fast_time / T << " s\n";
}

int main() {
  test_kmp();
  benchmark_prefix_functions(1000);
  return 0;
}
