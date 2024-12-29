cmake_minimum_required(VERSION 3.30)
project(stax_takehome)

set(CMAKE_CXX_STANDARD 20)

add_executable(stax_takehome main.cpp
        LinkedList.cpp
        LinkedList.h)

add_subdirectory(googletest)

enable_testing()

add_executable(
        ll_test
        test.cpp
        LinkedList.cpp
        LinkedList.h
)
target_link_libraries(
        ll_test
        GTest::gtest_main
        stdc++
)

include(GoogleTest)
gtest_discover_tests(ll_test)

