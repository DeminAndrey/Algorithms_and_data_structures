#pragma once

#include <string>

class Tester {
public:
  enum Figure {
    KING = 1,
    KNIGT = 2
  };

  Tester(int argc, char** argv);
  void all_run();
  bool run_test(const std::string& in,
                const std::string& out);

private:
	std::string in_file(int i) const;
	std::string out_file(int i) const;
  std::string m_test_path;
  Figure m_figure;
};
