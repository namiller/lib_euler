cmake_minimum_required(VERSION 3.1)

get_filename_component(CUR_DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${CUR_DIR}) # set project name to directory name.

SET(PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
SET(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

SET(PROJECT_UNDER_TEST "${PROJECT_NAME}") #used by the included test to determine link deps.

# This copies the include/ header files into a folder with the project name under the output include path
file(COPY "${PROJECT_INCLUDE_DIR}/" DESTINATION "${INCLUDE_OUTPUT_PATH}/${PROJECT_NAME}")

# automatically depends on all cpp files in source directory
file(GLOB SRCS ${PROJECT_SOURCE_DIR}/*.cpp)

include_directories(${PROJECT_INCLUDE_DIR} ${GENERATED_INCLUDE_PATH})
add_library(${PROJECT_NAME} SHARED ${SRCS})

#target_link_libraries(${PROJECT_NAME} dep) #TODO: uncomment and change dep -> whatever subproject dependency(s) this has.

add_subdirectory(test)
