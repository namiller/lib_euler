cmake_minimum_required(VERSION 3.1)
project(integration_test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${GENERATED_INCLUDE_PATH})

set(EXECUTABLE_OUTPUT_PATH "${TEST_OUTPUT_PATH}") #output to the correct dir

add_executable(${PROJECT_NAME} main.cpp) #TODO: change this if the test file changes

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread sub1 sub2) #TODO:change these references to the other subprojects (name is of project, not of folder)
add_test(NAME integration_test COMMAND ${PROJECT_NAME})
