#include <numeric>
#include <string>
#include <stdexcept>

/**
 * @brief Расчёт справедливого деления гороха между Сусликом и Хомой
 * @param a - числитель первой дроби
 * @param b - знаменатель первой дроби
 * @param c - числитель второй дроби
 * @param d - знаменатель второй дроби
 * @return результат сложения двух дробей представленную в виде строки
 * @exception если в знаменателе любой дроби нулевое значение
 */
std::string suslik_and_homa(int a, int b, int c, int d) {
  if (b == 0 || d == 0) {
    throw std::invalid_argument("Zero denominator!");
  }
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

