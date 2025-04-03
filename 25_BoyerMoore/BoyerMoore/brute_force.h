#include <vector>
#include <string>

/**
 * @brief Функция реализует алгоритм полного перебора для поиска всех
 *  вхождений подстроки pattern в строку text
 * @param text - строка, в которой необходимо выполнить поиск подстроки
 * @param pattern - строка, представляющая подстроку, которую мы ищем в text
 * @return - вектор целых чисел, содержащий индексы начала каждого вхождения
 *  подстроки pattern в строку text. Если подстрока не найдена, возвращается пустой вектор
 */
std::vector<int> bruteForceSearch(const std::string& text,
                                  const std::string& pattern) {
  const int n = text.size();
  const int m = pattern.size();

  std::vector<int> result;
  for (int i = 0; i <= n - m; ++i) {
    int j;
    for (j = 0; j < m; ++j) {
      if (text[i + j] != pattern[j])
        break;
    }
    if (j == m)
      result.push_back(i);
  }
  return result;
}
