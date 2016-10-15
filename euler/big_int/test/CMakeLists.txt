cmake_minimum_required(VERSION 3.1)
project(${PROJECT_UNDER_TEST}_test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH "${TEST_OUTPUT_PATH}")

add_executable(${PROJECT_NAME}_1 bcd_test.cpp)
add_executable(${PROJECT_NAME}_2 signed_test.cpp)
add_executable(${PROJECT_NAME}_3 unsigned_test.cpp)

target_link_libraries(${PROJECT_NAME}_1 ${GTEST_LIBRARIES} pthread ${PROJECT_UNDER_TEST})
target_link_libraries(${PROJECT_NAME}_2 ${GTEST_LIBRARIES} pthread ${PROJECT_UNDER_TEST})
target_link_libraries(${PROJECT_NAME}_3 ${GTEST_LIBRARIES} pthread ${PROJECT_UNDER_TEST})

add_test(NAME ${PROJECT_UNDER_TEST}_unit1 COMMAND ${PROJECT_NAME}_1)
add_test(NAME ${PROJECT_UNDER_TEST}_unit2 COMMAND ${PROJECT_NAME}_2)
add_test(NAME ${PROJECT_UNDER_TEST}_unit3 COMMAND ${PROJECT_NAME}_3)
