add_library(GPAC SHARED IMPORTED GLOBAL)
set_target_properties(GPAC PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/libgpac.so.12.10.0")
target_include_directories(GPAC INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")