#include "boyer_moore.h"
#include "brute_force.h"

#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <vector>


using namespace std;

double measureTime(const function<void()>& func) {
  auto start = chrono::high_resolution_clock::now();
  func();
  auto end = chrono::high_resolution_clock::now();
  return chrono::duration<double>(end - start).count();
}

template <typename Func>
void testAlgorithm(const string& name, const string& text,
                   const string& pattern,
                   Func&& searchFunc) {
  const int N = 1000;
  double total_duration = 0;
  vector<int> result;

  for (int i = 0; i < N; ++i) {
    total_duration += measureTime([&]() {
      result = searchFunc(text, pattern);
    });
  }

  cout << left << setw(25) << name
       << "| Найдено: " << setw(5) << result.size()
       << "| Среднее время: " << total_duration / N << " сек" << endl;
}

int main() {
  string text = "ABAAABCDABCABCABCD";
  string pattern = "ABC";

  setlocale(LC_ALL, "ru_RU.UTF-8");

  cout << "Сравнение алгоритмов:\n";
  cout << "------------------------------------------------------\n";
  testAlgorithm("Бойер-Мур", text, pattern, boyerMooreSearch);
  testAlgorithm("Полный перебор", text, pattern, bruteForceSearch);
  cout << "------------------------------------------------------\n";

  return 0;
}

