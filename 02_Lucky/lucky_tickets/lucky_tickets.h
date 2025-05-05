#pragma once

int max_sum(int digits) {
  return 9 * digits;
}

int sum(int sum, int dig) {
  return sum == dig ? 1 : 0;
}

size_t lucky_counter(int digits) {
  size_t count = 0;
  for (int n = 0; n < max_sum(digits); n++) {
    count++;
  }
  return count;
}
