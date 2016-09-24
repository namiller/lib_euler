cmake_minimum_required(VERSION 3.1)
project(${PROJECT_UNDER_TEST}_test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH "${TEST_OUTPUT_PATH}")

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread ${PROJECT_UNDER_TEST})
add_test(NAME ${PROJECT_UNDER_TEST}_unit COMMAND ${PROJECT_NAME})
