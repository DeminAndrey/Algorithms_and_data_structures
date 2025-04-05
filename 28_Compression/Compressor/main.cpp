#include <iostream>
#include <vector>
#include <string>
#include "RLE.h"
#include "EnhancedRLE.h"
#include "FileUtils.h"

enum class Mode { Compress, Decompress };

void printUsage()
{
    std::cout << "Usage:" << std::endl;
    std::cout << "./program [-m mode] input_file output_file" << std::endl;
    std::cout << "-m mode: specify the operation mode (compress or decompress)" << std::endl;
    std::cout << "input_file: path to the input file" << std::endl;
    std::cout << "output_file: path to the output file" << std::endl;
}

Mode parseMode(const std::string& modeStr)
{
    if (modeStr == "compress")
    {
        return Mode::Compress;
    }
    else if (modeStr == "decompress")
    {
        return Mode::Decompress;
    }
    else
    {
        throw std::invalid_argument("Invalid mode specified");
    }
}

/*
  Описание параметров командной строки
 ./rle_compressor -m <mode> [-e] <input_file> <output_file>
  Параметры:
  -m <mode>: Определяет режим работы программы. Возможные значения:
  compress: Сжимает входной файл.
  decompress: Распаковывает сжатый файл.
  [-e]: Опциональный параметр. Если указан, используется улучшенная версия алгоритма RLE. По умолчанию используется базовый алгоритм RLE.
  <input_file>: Путь к входному файлу. Этот файл будет использоваться для сжатия или распаковки в зависимости от режима.
  <output_file>: Путь к выходному файлу. Сюда будет записан результат сжатия или распаковки.

  Примеры использования:

  Базовая компрессия файла:
  ./rle_compressor -m compress input.txt output.rle

  Улучшенная компрессия файла:
  ./rle_compressor -m compress -e input.jpg output.rle

  Декомпрессия файла:
  ./rle_compressor -m decompress compressed.rle original.txt

  Декомпрессия файла с использованием улучшенного алгоритма:
  ./rle_compressor -m decompress -e enhanced.rle original.png
*/

int main(int argc, char* argv[])
{
  for (int i = 0; i < argc; ++i) {
    std::cout << argv[i] << std::endl;
  }

    if (argc != 5 && argc != 6)
    {
        std::cerr << "Too few arguments for start" << std::endl;
        printUsage();
        return EXIT_FAILURE;
    }

    bool useEnhanced = false;
    Mode mode = Mode::Compress;
    std::string inputFile, outputFile;

    if (argc == 6)
    {
        if (strcmp(argv[1], "-m") != 0 || strcmp(argv[3], "-e") != 0)
        {
            std::cerr << "Wrong argument" << std::endl;
            printUsage();
            return EXIT_FAILURE;
        }

        mode = parseMode(std::string(argv[2]));
        useEnhanced = true;
        inputFile = argv[4];
        outputFile = argv[5];
    }
    else if (argc == 5)
    {
        if (strcmp(argv[1], "-m") != 0)
        {
            printUsage();
            return EXIT_FAILURE;
        }

        mode = parseMode(std::string(argv[2]));
        inputFile = argv[3];
        outputFile = argv[4];
    }

    try
    {
        auto data = readFile(inputFile);

        std::vector<unsigned char> result;
        switch (mode)
        {
            case Mode::Compress:
                if (useEnhanced)
                {
                    result = enhancedCompress(data);
                }
                else
                {
                    result = compress(data);
                }
                break;
            case Mode::Decompress:
                if (useEnhanced)
                {
                    result = enhancedDecompress(data);
                }
                else
                {
                    result = decompress(data);
                }
                break;
        }

        writeFile(outputFile, result);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
