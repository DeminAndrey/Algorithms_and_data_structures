#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>

// Читает содержимое файла в вектор байтов
std::vector<unsigned char> readFile(const std::string& fileName);

// Записывает данные в файл
void writeFile(const std::string& fileName,
               const std::vector<unsigned char>& data);

#endif // FILE_UTILS_H
