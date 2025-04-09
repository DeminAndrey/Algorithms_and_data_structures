cmake_minimum_required(VERSION 3.10)

project(KnuthMorrisPratt)

set(CMAKE_CXX_STANDARD 17)

add_executable(kmp_main
  main.cxx
  kmp.cxx)

add_executable(kmp_test
  test.cxx
  kmp.cxx)
