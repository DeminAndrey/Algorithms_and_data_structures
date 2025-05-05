#include "FactorArray.h"
#include "MatrixArray.h"
#include "VectorArray.h"

#include <chrono>
#include <iostream>
#include <vector>

const int N = 10000;

using namespace std;

size_t current() {
  return chrono::duration_cast<chrono::milliseconds>(
             chrono::system_clock::now().time_since_epoch()).count();
}

void printArr(Array<int> *arr) {
  cout << "SIZE = " << arr->size() << "\n";
  for (size_t i = 0; i < arr->size(); i++)
    cout << arr->value(i) << " ";
  cout << "\n";
}

void putValues(Array<int> *arr, int N) {
  cout << "PUT VALUES" << "\n";
  for (int n = 100; n <= N; n *= 10) {
    cout << "N = " << n << "\n";

    size_t start = current();
    for (int val = 0; val < n; val++) {
      try {
        arr->put(val);
      }
      catch (const exception &ex) {
        cout << ex.what() << endl;
      }
    }
    size_t end = current();

    cout << arr->name() << ": " << "realloc: " << arr->realloc()
         << ", elapsed time: " << end - start << " ms"
         << "\n";
  }
  arr->resetRealloc();
}

void addValues(Array<int> *arr, int N) {
  cout << "ADD VALUES" << "\n";
  for (int n = 100; n <= N; n *= 10) {
    cout << "N = " << n << "\n";

    size_t start = current();
    for (int val = 0; val < n; val++) {
      try {
        arr->add(val, 0);
      }
      catch (const exception &ex) {
        cout << ex.what() << endl;
      }
    }
    size_t end = current();

    cout << arr->name() << ": " << "realloc: " << arr->realloc()
         << ", elapsed time: " << end - start << " ms"
         << "\n";
  }
  arr->resetRealloc();
}

void removeValues(Array<int> *arr) {
  cout << "REMOVE VALUES" << "\n";
  size_t start = current();

  while (arr->size()) {
    try {
      ignore = arr->remove(0);
    }
    catch (const exception &ex) {
      cout << ex.what() << endl;
    }
  }
  size_t end = current();

  cout << arr->name() << ": " << "realloc: " << arr->realloc()
       << ", elapsed time: " << end - start << " ms"
       << "\n";

  arr->resetRealloc();
}

void arraysDoWork(const vector<Array<int>*> &container) {
  for (auto arr : container) {
    putValues(arr, N);
    addValues(arr, N);
    removeValues(arr);

    printArr(arr);
  }
}

void matrixDoWork() {
  cout << "PUT VALUES" << "\n";
  for (int n = 100; n <= N; n *= 10) {
    cout << "N = " << n << "\n";

    MatrixArray<int> matrix;
    size_t start = current();
    for (int val = 0; val < n; val++) {
      try {
        matrix.put(val);
      }
      catch (const exception &ex) {
        cout << ex.what() << endl;
      }
    }
    size_t end = current();

    cout << matrix.name() << ": " << "realloc: " << matrix.realloc()
         << ", elapsed time: " << end - start << " ms"
         << "\n";
  }
}

int main() {
  vector<Array<int>*> container;
  container.emplace_back(new VectorArray<int>());
  container.emplace_back(new FactorArray<int>());

  try {
    arraysDoWork(container);
    matrixDoWork();
  }
  catch (const exception &ex) {
    cout << ex.what() << endl;
  }

  return 0;
}
