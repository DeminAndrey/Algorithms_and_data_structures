#include "RLE.h"

std::vector<unsigned char> compress(const std::vector<unsigned char>& data)
{
    std::vector<unsigned char> result;
    
    for (size_t i = 0; i < data.size(); ++i)
    {
        unsigned char currentByte = data[i];
        int count = 1;
        
        while (i + 1 < data.size() && data[i + 1] == currentByte && count < 255)
        {
            ++count;
            ++i;
        }
        
        result.push_back(count);
        result.push_back(currentByte);
    }
    
    return result;
}

std::vector<unsigned char> decompress(const std::vector<unsigned char>& compressedData)
{
    std::vector<unsigned char> result;
    
    for (size_t i = 0; i < compressedData.size(); i += 2)
    {
        unsigned char count = compressedData[i];
        unsigned char byte = compressedData[i + 1];
        
        for (int j = 0; j < count; ++j)
        {
            result.push_back(byte);
        }
    }
    
    return result;
}