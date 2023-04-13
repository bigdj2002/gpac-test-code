cmake_minimum_required(VERSION 3.10)
project(mp4-parser)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
find_package(GPAC REQUIRED)

add_executable(program mp4parse.cpp)

target_include_directories(program PRIVATE ${GPAC_INCLUDE_DIRS})
target_link_libraries(program PRIVATE ${GPAC_LIBRARIES})