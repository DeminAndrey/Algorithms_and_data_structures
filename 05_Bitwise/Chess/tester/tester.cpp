#include "tester.hpp"
#include "../chess.hpp"

#include <iostream>
#include <fstream>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

enum Figure {
  King = 1,
  Knigt = 2
};

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

void Tester::run() {
  std::cout << "test path: " << m_test_path << "\n" << std::endl;

  int test_num = 0;
  while (true) {
    std::ifstream fin(in_file(test_num));
    std::ifstream fout(out_file(test_num));

		if (!fin.good() || !fout.good()) {
			break;
		}

		std::string in{std::istreambuf_iterator<char>(fin),
                 	   std::istreambuf_iterator<char>()};
		std::string out{std::istreambuf_iterator<char>(fout),
                 	   std::istreambuf_iterator<char>()};

    bool success = run_test(in, out);

    std::cout << "test: " << test_num << ", success: "
              << std::boolalpha << success << "\n" << std::endl;

    ++test_num;
	}
}

bool get_moves(Figure figure, int pos) {
  switch (figure) {
  case Figure::King:
    return Chess::get_king_moves(pos);
  case Figure::Knigt:
    return Chess::get_knigt_moves(pos);
  }
}

bool run_test(const std::string& in, const std::string& out) {
  int in_pos = std::stoi(in);
  std::vector<std::string> splitted;
  auto out_vec = boost::algorithm::split(splitted, out,
                                         boost::algorithm::is_any_of("\n"),
                                         boost::token_compress_on);
  if (out_vec.size() < 2) {
    std::cout << "unexpected input: " << out << std::endl;
    return false;
  }

  int expected_moves_count = std::stoi(out_vec[0]);
  unsigned long long expected_moves_mask = std::stoull(out_vec[1]);

  unsigned long long computed_moves_mask = Chess::get_king_moves(in_pos);
  int computed_moves_count = BitCounter::counting_by_subtraction(computed_moves_mask);

  std::cout << "for position " << std::dec << in_pos << ", moves count: "
            << computed_moves_count << " and mask: 0x" << std::hex
            << computed_moves_mask << std::endl;

  return expected_moves_count == computed_moves_count &&
         expected_moves_mask == computed_moves_mask;
}

int main(int argc, char** argv) {
  Tester tester(argc, argv);
  tester.run();

  return EXIT_SUCCESS;
}
