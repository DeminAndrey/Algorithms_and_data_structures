#include "boyer_moore.h"

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Функция предварительной обработки: таблица плохих символов
unordered_map<char, int> badCharacterTable(const string& pattern) {
  unordered_map<char, int> badChar;
  int patternSize = pattern.size();
  for (int i = 0; i < patternSize - 1; i++) {
    badChar[pattern[i]] = patternSize - 1 - i;
  }
  return badChar;
}

// Функция предварительной обработки: таблица хороших суффиксов
vector<int> goodSuffixTable(const string& pattern) {
  const int patternSize = pattern.size();
  vector<int> suffix(patternSize, patternSize);
  vector<int> border(patternSize + 1, 0);

  int j = patternSize;
  for (int i = patternSize; i > 0; --i) {
    border[i] = j;
    while (j < patternSize && pattern[i - 1] != pattern[j - 1]) {
      if (suffix[j] == patternSize) {
        suffix[j] = j - i;
      }
      j = border[j];
    }
    j--;
  }

  for (int i = 0; i < patternSize - 1; ++i) {
    suffix[i] = border[i + 1];
  }
  return suffix;
}

vector<int> boyerMooreSearch(const string& text,
                             const string& pattern) {
  if (pattern.empty() || text.size() < pattern.size()) {
    return {};
  }
  vector<int> result;
  const int textSize = text.size();
  const int patternSize = pattern.size();

  auto badChar = badCharacterTable(pattern);
  auto goodSuffix = goodSuffixTable(pattern);

  int s = 0;
  while (s <= (textSize - patternSize)) {
    int j = patternSize - 1;
    while (j >= 0 && pattern[j] == text[s + j]) {
      j--;
    }
    if (j < 0) {
      result.push_back(s);
      s += goodSuffix[0];
    } else {
      int badCharShift = badChar.count(text[s + j]) ? badChar[text[s + j]] : patternSize;
      int goodSuffixShift = goodSuffix[j];
      s += max(badCharShift, goodSuffixShift);
    }
  }
  return result;
}
