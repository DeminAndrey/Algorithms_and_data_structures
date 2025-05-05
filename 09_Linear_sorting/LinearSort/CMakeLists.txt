cmake_minimum_required(VERSION 3.5)

project(LinearSort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LinearSort
  main.cxx
  sorts.h
  sorts.cxx)

include(GNUInstallDirs)
install(TARGETS LinearSort
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
