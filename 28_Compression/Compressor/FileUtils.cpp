#include "FileUtils.h"

#include <fstream>

std::vector<unsigned char> readFile(const std::string& fileName)
{
    std::ifstream file(fileName, std::ios::binary | std::ios::ate);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file");
    }
    
    std::streampos size = file.tellg();
    file.seekg(0, std::ios::beg);
    
    std::vector<unsigned char> buffer(size);
    file.read((char*)buffer.data(), size);
    
    return buffer;
}

void writeFile(const std::string& fileName, const std::vector<unsigned char>& data)
{
    std::ofstream file(fileName, std::ios::binary);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to create file");
    }
    
    file.write((const char*)data.data(), data.size());
}
