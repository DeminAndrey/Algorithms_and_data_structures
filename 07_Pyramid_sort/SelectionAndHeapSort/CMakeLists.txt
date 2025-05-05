cmake_minimum_required(VERSION 3.5)

project(SelectionAndHeapSort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SelectionAndHeapSort main.cxx
  sorts.h)

include(GNUInstallDirs)
install(TARGETS SelectionAndHeapSort
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
