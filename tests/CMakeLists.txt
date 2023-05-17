# Generating file of printing MP4 information
add_executable(print_mp4_info print_mp4_info.cpp)
target_include_directories(print_mp4_info PRIVATE ${GPAC_INCLUDE_DIR})
target_link_libraries(print_mp4_info PRIVATE gpac220 pthread)
target_compile_options(print_mp4_info PRIVATE -Wall -Werror)