#ifndef ENHANCED_RLE_H
#define ENHANCED_RLE_H

#include <vector>

// Улучшенная функция сжатия массива байтов по алгоритму RLE
std::vector<unsigned char> enhancedCompress(const std::vector<unsigned char>& data);

// Улучшенная функция распаковки сжатого массива байтов
std::vector<unsigned char> enhancedDecompress(const std::vector<unsigned char>& compressedData);

#endif // ENHANCED_RLE_H
