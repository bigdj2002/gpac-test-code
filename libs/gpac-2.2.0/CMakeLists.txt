add_library(gpac220 SHARED IMPORTED GLOBAL)
set_target_properties(gpac220 PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/libgpac.so.12.10.0")
target_include_directories(gpac220 INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")