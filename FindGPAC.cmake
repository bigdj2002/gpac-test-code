find_path(GPAC_INCLUDE_DIR
  NAMES gpac/configuration.h
  PATH_SUFFIXES gpac
)

find_library(GPAC_LIBRARY
  NAMES gpac
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GPAC DEFAULT_MSG GPAC_LIBRARY GPAC_INCLUDE_DIR)

if(GPAC_FOUND)
  set(GPAC_LIBRARIES ${GPAC_LIBRARY})
  set(GPAC_INCLUDE_DIRS ${GPAC_INCLUDE_DIR})
endif()

mark_as_advanced(GPAC_LIBRARY GPAC_INCLUDE_DIR)