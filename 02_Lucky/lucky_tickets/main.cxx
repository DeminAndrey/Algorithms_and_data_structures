#include "lucky_tickets.h"

#include <iostream>

using namespace std;

int main() {
  for (int n = 1; n <= 10; n++) {
    cout << n << ", lucky_count: " << lucky_counter(n) << endl;
  }

  return 0;
}
