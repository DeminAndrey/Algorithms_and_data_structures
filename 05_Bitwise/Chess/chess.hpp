#include <array>

class BitCounter {
public:
  BitCounter() = default;

  static int counting_by_shift(unsigned long long mask) {
    int cnt = 0;
    while (mask) {
      if (mask & 1) {
        cnt++;
      }
      mask >>= 1;
    }

    return cnt;
  }

  static int counting_by_subtraction(unsigned long long mask) {
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

namespace Chess {
unsigned long long get_king_moves(int pos) {
  unsigned long long bb = 1; // битовое представление индекса
  bb = bb << pos;

  unsigned long long mask = 0; // битовая маска возможных ходов
  unsigned long long left_side_mask = 0xFEFEFEFEFEFEFEFE;
  unsigned long long right_side_mask = 0x7F7F7F7F7F7F7F7F;

  mask = (bb & left_side_mask) >> 1; // влево
  mask |= (bb & left_side_mask) << 7; //  вверх влево
  mask |= (bb & left_side_mask) >> 9; // вниз влево

  mask |= (bb & right_side_mask) << 1; //  вправо
  mask |= (bb & right_side_mask) >> 7; // вниз вправо
  mask |= (bb & right_side_mask) << 9; //  вверх вправо

  mask |=  bb >> 8;                       // вниз
  mask |= bb << 8;                        //  вверх

  return mask;
}

unsigned long long get_knigt_moves(int pos) {
  unsigned long long bb = 1; // битовое представление индекса
  bb = bb << pos;

  unsigned long long mask = 0; // битовая маска возможных ходов
  unsigned long long left_side_mask = 0xFEFEFEFEFEFEFEFE;
  unsigned long long left_side_mask2 = 0xFCFCFCFCFCFCFCFC;
  unsigned long long right_side_mask = 0x7F7F7F7F7F7F7F7F;
  unsigned long long right_side_mask2 = 0x3F3F3F3F3F3F3F3F;

  mask = (bb & left_side_mask2) << 6; // влево вверх
  mask |= (bb & left_side_mask) << 15; //  влево вверх
  mask |= (bb & left_side_mask2) >> 10; // влево вниз
  mask |= (bb & left_side_mask) >> 17; // влево вниз
  mask |= (bb & right_side_mask2) << 10; //  вправо вверх
  mask |= (bb & right_side_mask) << 17; //  вправо вверх
  mask |= (bb & right_side_mask2) >> 6; //  вправо вниз
  mask |= (bb & right_side_mask) >> 15; //  вправо вниз

  return mask;
}
} // namespace Chess

