cmake_minimum_required(VERSION 3.5)

project(arrays LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(arrays
  main.cxx
  Array.h
  SingleArray.h
  SingleArray.cxx
  VectorArray.h
  VectorArray.cxx
  FactorArray.h
  FactorArray.cxx
  MatrixArray.h
  MatrixArray.cxx
)

include(GNUInstallDirs)
install(TARGETS arrays
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
