cmake_minimum_required(VERSION 3.10)
project(RLE_Compressor)

set(CMAKE_CXX_STANDARD 17)

add_executable(rle_compressor
  main.cpp
  RLE.h
  RLE.cpp
  EnhancedRLE.h
  EnhancedRLE.cpp
  FileUtils.h
  FileUtils.cpp)

target_include_directories(rle_compressor
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
