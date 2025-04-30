#include "RLE.h"

std::vector<unsigned char> compress(const std::vector<unsigned char>& data) {
  std::vector<unsigned char> result;
  const int threshold = 4; // минимальный размер серии для применения RLE

  for (size_t i = 0; i < data.size(); ) {
    unsigned char currentByte = data[i];
    int count = 1;

    // подсчитываем длину текущей серии
    while ((i + 1 < data.size()) && (data[i + 1] == currentByte)) {
      ++count;
      ++i;
    }

    if (count >= threshold) {
      // если серия достаточна длинная, применяем упаковку
      result.push_back(0x00);       // вводим маркер начала серий
      result.push_back(count);      // записываем счетчик
      result.push_back(currentByte); // записываем повторяющийся элемент
    }
    else {
      // если серия короткая или одиночная, добавляем как есть
      for (int j = 0; j < count; ++j) {
        result.push_back(currentByte);
      }
    }
    ++i;
  }
  return result;
}

std::vector<unsigned char> decompress(const std::vector<unsigned char>& compressedData) {
  std::vector<unsigned char> result;
  size_t i = 0;

  while (i < compressedData.size()) {
    if (compressedData[i] == 0x00) { // встретили маркер начала серий
      i++;                         // пропускаем маркер
      unsigned char count = compressedData[i]; // читаем счетчик
      unsigned char byte = compressedData[i + 1]; // читаем повторяющийся байт

      for (unsigned char j = 0; j < count; ++j) {
        result.push_back(byte);
      }
      i += 2;                      // переходим к следующему блоку
    }
    else {
      // если это не маркер, значит это одиночный байт
      result.push_back(compressedData[i]);
      i++;
    }
  }
  return result;
}
