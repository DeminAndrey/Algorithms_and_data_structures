#pragma once

#include <string>
#include <vector>

/**
 * @brief Функция реализует алгоритм Бойера-Мура для поиска всех
 *  вхождений подстроки (шаблона) pattern в строку text
 * @param text - строка, в которой необходимо выполнить поиск подстроки
 * @param pattern - строка, представляющая подстроку, которую мы ищем в text
 * @return - вектор целых чисел, содержащий индексы начала каждого вхождения
 *  подстроки pattern в строку text. Если подстрока не найдена, возвращается пустой вектор
 */
std::vector<int> boyerMooreSearch(const std::string& text,
                                  const std::string& pattern);
