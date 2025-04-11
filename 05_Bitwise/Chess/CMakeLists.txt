cmake_minimum_required(VERSION 3.5)

project(Chess LANGUAGES CXX)

find_package(Boost)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Chess
  chess.hpp
  tester/tester.hpp
  tester/tester.cpp
)

target_include_directories(Chess
  PRIVATE ${Boost_INCLUDE_DIR}
)

target_link_libraries(Chess
  PRIVATE ${Boost_LIBRARY_DIR}
)
