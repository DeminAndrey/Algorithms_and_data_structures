#include <iostream>
#include <numeric>
#include <ratio>
#include <utility>
#include <string>

/**
 * @brief suslik_and_homa
 * @param a
 * @param b
 * @param c
 * @param d
 * @return
 */
std::string suslik_and_homa(int a, int b, int c, int d) {
  // Найти сумму дробей
  int numerator = a * d + b * c;
  int denominator = b * d;

  // Найти НОД для сокращения дроби
  int gcd_value = std::gcd(numerator, denominator);

  // Разделить числитель и знаменатель на НОД
  numerator /= gcd_value;
  denominator /= gcd_value;

  return std::to_string(numerator) + "/" + std::to_string(denominator);
}

