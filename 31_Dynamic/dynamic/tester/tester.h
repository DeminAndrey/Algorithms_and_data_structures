#pragma once

#include <string>

class Tester {
public:
  Tester(int argc, char** argv);
  void run_all();

private:
	std::string in_file(int i) const;
	std::string out_file(int i) const;
  std::string m_test_path;
};

// тестирование задачи про суслика и Хому, делящих горох
bool test_1(const std::string& in, const std::string& out);
// тестирование задачи про N-значные числа из цифр 5 и 8
bool test_3(const std::string& in, const std::string& out);
