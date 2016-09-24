cmake_minimum_required(VERSION 3.1)
project (euler) # this project name can be changed but it shouldn't really change much.

enable_testing()

## this is the only CMAKE VERSION 2.6+ feature used so removing it allows back comp.
set(CMAKE_CXX_STANDARD 14) #use c++14
#set(CMAKE_CXX_STANDARD 11) #use c++11

# the following variables can be changed to effect the location of the build products.
set(INCLUDE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/include")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")
set(TEST_OUTPUT_PATH "${PROJECT_BINARY_DIR}/tests")

#must be set elsewhere for subprojects to compile independantly 
set(GENERATED_INCLUDE_PATH "${INCLUDE_OUTPUT_PATH}")

#TODO: change the following lines to add the correct submodule directories
add_subdirectory(nums)  # this (sub1) must match the name of the directory (not necisarilly the name of the project)
add_subdirectory(serialize)  # ditto
#add_subdirectory(linear)  # ditto
#add_subdirectory(perms)  # ditto
#add_subdirectory(big_int)  # ditto
#add_subdirectory(test)  # ditto
