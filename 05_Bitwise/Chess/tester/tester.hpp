#pragma once

#include <string>

class Tester {
public:
  Tester(int argc, char** argv);
	void run();

private:
	std::string in_file(int i) const;
	std::string out_file(int i) const;
  std::string m_test_path;
};

bool run_test(const std::string& in, const std::string& out);
