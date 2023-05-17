cmake_minimum_required(VERSION 3.10)

project(gpac-test-codes)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(GPAC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/gpac-2.2.0/include)

add_subdirectory(libs)
add_subdirectory(tests)