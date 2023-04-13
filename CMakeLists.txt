cmake_minimum_required(VERSION 3.10)
project(mp4-parser)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GPAC REQUIRED gpac)

add_executable(program mp4parse.cpp)

target_include_directories(program PRIVATE ${GPAC_INCLUDE_DIRS})
target_link_libraries(program PRIVATE ${GPAC_LIBRARIES})
target_compile_options(program PRIVATE ${GPAC_CFLAGS_OTHER})