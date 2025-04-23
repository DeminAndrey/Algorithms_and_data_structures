cmake_minimum_required(VERSION 3.10)

project(SortingProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Все исполняемые файлы
add_subdirectory(src)

install(TARGETS sorting_app DESTINATION bin)

enable_testing()

add_executable(run_tests tests/main.cxx)

target_link_libraries(run_tests
  PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
  PRIVATE GTest::gtest_main
  PRIVATE SorterLib
)

add_test(NAME run_tests COMMAND run_tests)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
gtest_discover_tests(run_tests)

