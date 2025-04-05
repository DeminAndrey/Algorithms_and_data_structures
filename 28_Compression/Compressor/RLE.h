#ifndef RLE_H
#define RLE_H

#include <vector>

// Функция сжатия массива байтов по алгоритму RLE
std::vector<unsigned char> compress(const std::vector<unsigned char>& data);

// Функция распаковки сжатого массива байтов
std::vector<unsigned char> decompress(const std::vector<unsigned char>& compressedData);

#endif // RLE_H
