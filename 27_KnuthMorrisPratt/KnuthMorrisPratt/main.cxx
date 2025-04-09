#include "kmp.h"

#include <iostream>

int main() {
  std::string text = "abcxabcdabcdabcy";
  std::string pattern = "abcdabcy";

  std::cout << "Text: " << text << "\nPattern: " << pattern << "\n\n";

  knuth_morris_pratt(text, pattern);

  return 0;
}
