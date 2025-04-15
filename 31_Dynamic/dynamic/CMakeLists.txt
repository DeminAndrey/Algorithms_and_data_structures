cmake_minimum_required(VERSION 3.5)

project(dynamic LANGUAGES CXX)

find_package(Boost)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dynamic
  main.cxx
  task1.h
  task2.h
  task3.h
  task4.h
  tester/tester.hpp
  tester/tester.cpp
)

target_include_directories(dynamic
  PRIVATE ${Boost_INCLUDE_DIR}
)

target_link_libraries(dynamic
  PRIVATE ${Boost_LIBRARY_DIR}
)
