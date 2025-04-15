#include "tester.hpp"
#include "../task1.h"
#include "../task2.h"

#include <iostream>
#include <fstream>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>


Tester::Tester(int argc, char** argv) {
	if (argc < 2) {
    std::cout << "test path not specifed" << std::endl;
    exit(EXIT_FAILURE);
	}
  m_test_path = argv[1];
}

std::string Tester::in_file(int i) const {
  return m_test_path + "/test." + std::to_string(i) + ".in";
}

std::string Tester::out_file(int i) const {
  return m_test_path + "/test." + std::to_string(i) + ".out";
}

void Tester::run_all() {
  std::cout << "test path: " << m_test_path << "\n" << std::endl;

  int test_num = 0;
  while (true) {
    std::ifstream fin(in_file(test_num));
    std::ifstream fout(out_file(test_num));

		if (!fin.good() || !fout.good()) {
			break;
		}

    std::string in{std::istreambuf_iterator<char>(fin), {}};
    std::string out{std::istreambuf_iterator<char>(fout), {}};

    in.erase(std::remove(in.begin(), in.end(), '\n'), in.end());
    out.erase(std::remove(out.begin(), out.end(), '\n'), out.end());

    // здесь нужно указать нужныый тест test_1, test_2
    bool success = test_1(in, out);

    std::cout << "test: " << test_num << ", success: "
              << std::boolalpha << success << "\n" << std::endl;

    ++test_num;
	}
}

bool test_1(const std::string& in, const std::string& out) {
  if (out.empty()) {
    std::cout << "unexpected input: " << out << std::endl;
    return false;
  }

  std::vector<std::string> in_vec;
  boost::algorithm::split(in_vec, in,
                          boost::algorithm::is_any_of("+/"),
                          boost::token_compress_on);
  if (in_vec.size() < 4) {
    std::cout << "unexpected input: " << in << std::endl;
    return false;
  }

  int a = std::stoi(in_vec[0]);
  int b = std::stoi(in_vec[1]);
  int c = std::stoi(in_vec[2]);
  int d = std::stoi(in_vec[3]);

  auto computed = suslik_and_homa(a, b, c, d);

  return computed == out;
}

bool test_2(const std::string& in, const std::string& out) {
  if (in.empty() || out.empty()) {
    std::cout << "unexpected input!" << std::endl;
    return false;
  }

  int N = std::stoi(in);
  int computed = numbers_from_5_and_8(N);

  int expected = std::stoi(out);

  return computed == expected;
}
