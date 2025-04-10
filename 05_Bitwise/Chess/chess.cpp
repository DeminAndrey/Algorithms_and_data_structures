#include "tester/tester.hpp"

#include <array>
#include <iostream>
#include <string>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

class BitCounter {
public:
    BitCounter() = default;

    static int counting_by_shift(unsigned long mask) {
        int cnt = 0;
        while (mask) {
            if (mask & 1) {
                cnt++;
            }
            mask >>= 1;
        }

        return cnt;
    }

    static int counting_by_subtraction(unsigned long mask) {
        int cnt = 0;
        while (mask) {
            cnt++;
            mask &= mask - 1;
        }

        return cnt;
    }

    static int counting_by_table(unsigned long  long mask) {
        int cnt = 0;
        while (mask) {
            cnt += bits_[mask & 0xff];
            mask >>= 8;
        }

        return cnt;
    }

private:
    static std::array<int, 256> init_bits() {
        std::array<int, 256> result;
        
        for (size_t i = 0; i < 256; ++i) {
            result[i] = counting_by_subtraction(i);
        }

        return result;
    }

    static std::array<int, 256> bits_;
};

std::array<int, 256> BitCounter::bits_ = BitCounter::init_bits();


unsigned long get_king_moves(int pos) {
    unsigned long K = 1ul << pos;
    unsigned long Ka = K & 0xfefefefefefefefe;
    unsigned long Kh = K & 0x7f7f7f7f7f7f7f7f;

    unsigned long mask =
        (Ka << 7) | (K << 8) | (Kh << 9) |
        (Ka >> 1) |            (Kh << 1) |
        (Ka >> 9) | (K >> 8) | (Kh >> 7);

    return mask;
}

unsigned long get_knigt_moves(int pos) {
    unsigned long K = 1ul << pos;
    unsigned long Ka = K & 0xfefefefefefefefe;
    unsigned long Ka2 = K & 0xfcfcfcfcfcfcfcfc;
    unsigned long Kh = K & 0x7f7f7f7f7f7f7f7f;
    unsigned long Kh2 = K & 0x3f3f3f3f3f3f3f3f;

    unsigned long mask =
                    (Ka << 15) | (Kh << 17) |
        (Ka2 << 6)  |                         (Kh2 << 10) |
        (Ka2 >> 10) |                         (Kh2 >> 6) |
                    (Ka >> 17) | (Kh >> 15);

    return mask;
}

bool test(const std::string& in, const std::string& out) {
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

  unsigned long long computed_moves_mask = get_king_moves(in_pos);
  int computed_moves_count = BitCounter::counting_by_table(computed_moves_mask);

  std::cout << "for position " << std::dec << in_pos << ", moves count: "
            << computed_moves_count << " and mask: 0x" << std::hex
            << computed_moves_mask << std::endl;

  return expected_moves_count == computed_moves_count &&
           expected_moves_mask == computed_moves_mask;
}

int main(int argc, char** argv) {
  Tester{argc, argv, test}.run();
}
