#include <iostream>
#include "math.h"

using namespace std;

int main()
{
  for (int x = 0; x < 25; x++) {
    for (int y = 0; y < 25; y++) {
      if (floor(y / 2.0) == x)
        cout << "# ";
      else
        cout << ". ";
    }
    cout << "\n";
  }

  return 0;
}
