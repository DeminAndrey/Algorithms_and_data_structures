#ifndef KMP_H
#define KMP_H

#include <string>
#include <vector>

// Медленная версия префикс-функции
std::vector<int> prefix_function_naive(const std::string& pattern);

// Быстрая версия префикс-функции
std::vector<int> prefix_function_fast(const std::string& pattern);

// Алгоритм КМП для поиска шаблона в строке
void knuth_morris_pratt(const std::string& text,
                        const std::string& pattern);

#endif // KMP_H
