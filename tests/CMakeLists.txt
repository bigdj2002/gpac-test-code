file(GLOB_RECURSE SRC1_FILES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_executable(mp4parse ${SRC1_FILES})

# target_include_directories(mp4parse PRIVATE ${GPAC_INCLUDE_DIR})
target_link_libraries(mp4parse PRIVATE gpac220 pthread)
target_compile_options(mp4parse PRIVATE -Wall -Werror)