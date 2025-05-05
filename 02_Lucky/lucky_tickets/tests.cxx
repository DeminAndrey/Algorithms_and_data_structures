#include "lucky_tickets.h"

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

TEST(lucky_tickets, lucky_counter)
{
  for (int n = 0; n <= 9; n++)
  {
    std::string nameIn = "test." + std::to_string(n) + ".in";
    std::string nameOut = "test." + std::to_string(n) + ".out";

    auto fileIn = fs::current_path().append("Tests").append(nameIn);
    auto fileOut = fs::current_path().append("Tests").append(nameOut);

    ASSERT_TRUE(fs::exists(fileIn));
    ASSERT_TRUE(fs::exists(fileOut));

    std::ifstream stream;
    stream.open(fileIn);
    ASSERT_TRUE(stream.is_open());

    std::string input_data;
    std::getline(stream, input_data);
    stream.close();

    stream.open(fileOut);
    ASSERT_TRUE(stream.is_open());

    std::string output_data;
    std::getline(stream, output_data);
    stream.close();

    ASSERT_FALSE(input_data.empty() && output_data.empty());

    int digits = stoi(input_data); // преобразование входных данных в число
    size_t result = stoull(output_data); // преобразование выходных данных в число

    // проверка на равенство результатов расчета и выходных данных из файла
    ASSERT_EQ(lucky_counter(digits), result);
  }
}
