file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

project(AppMcHevcEnc)

set(APP_SOURCES
 ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(${PROJECT_NAME} ${APP_SOURCES} ${UTIL_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${UTIL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE McHevcEnc pthread)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DMC_LICENSE_PATH="${MC_LICENSE_PATH}" )