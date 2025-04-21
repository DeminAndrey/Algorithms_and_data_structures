#include "ArrayGenerator.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "Statistics.h"

#include <iostream>
#include <memory>

using namespace std;

// Функция красивого вывода таблицы статистики
void printComparisonTable(const vector<string>& names, const vector<double>& durations, const vector<int>& comparisons, const vector<int>& swaps) {
  cout << "+----------------------+------------------+-------------+------------+" << endl;
  cout << "| Algorithm            | Duration (ms)    | Comparisons | Swaps      |" << endl;
  cout << "+----------------------+------------------+-------------+------------+" << endl;

  for (size_t i = 0; i < names.size(); ++i) {
    string name = names[i];
    double duration = durations[i];
    int comp = comparisons[i];
    int swap = swaps[i];

    printf("| %-20s | %16.2lf | %11d | %10d |\n",
           name.c_str(), duration, comp, swap);
  }

  cout << "+----------------------+------------------+-------------+------------+" << endl;
}

// Получаем массив и применяем серию сортировок
void runAllSorts(vector<int>& originalData) {
  vector<string> names;
  vector<double> durations;
  vector<int> comparisons;
  vector<int> swaps;

  vector<unique_ptr<AbstractSorter>> sorters;

  sorters.push_back(make_unique<BubbleSort>());
  sorters.push_back(make_unique<InsertionSort>());
  sorters.push_back(make_unique<QuickSort>());

  for(auto& sorter : sorters) {
    vector<int> currentData(originalData); // Работаем с копией оригинала
    Stats results;
    sorter->sort(currentData, results);

    names.push_back(typeid(*sorter.get()).name());
    durations.push_back(results.duration_ms);
    comparisons.push_back(results.comparisons);
    swaps.push_back(results.swaps);
  }

  printComparisonTable(names, durations, comparisons, swaps);
}


int main() {
  try {
    vector<int> data = ArrayGenerator::generateRandomArray(10);
    cout << "Generated random array:\n";
    for (const auto& num : data) {
      cout << num << " ";
    }
    cout << "\n\n";

    runAllSorts(data);
  }
  catch(const exception &ex) {
    cerr << ex.what() << endl;
  }

  return 0;
}
