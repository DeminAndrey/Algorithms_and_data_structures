cmake_minimum_required(VERSION 3.5)

project(lucky_tickets LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lucky_tickets main.cxx
  lucky_tickets.h)

add_executable(tests tests.cxx)

include(GNUInstallDirs)
install(TARGETS lucky_tickets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)

enable_testing()
add_test(tests tests)
