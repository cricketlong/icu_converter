cmake_minimum_required(VERSION 3.0)
project(converter)
set(CMAKE_BINARY_DIR "/home/cricket/cpp/converter")

# add_definitions(-DU_DISABLE_VERSION_SUFFIX=0)
set(CMAKE_BUILD_TYPE Debug)

# Add icu files
set(ICU_ROOT_DIR "/home/cricket/cpp/icu/icu4c/source")
set(ICU_BUILD_DIR "icu")
add_subdirectory(${ICU_ROOT_DIR} icu)
include_directories("${ICU_ROOT_DIR}/common"
                    "${ICU_ROOT_DIR}/i18n")

add_executable(converter converter.cpp)
target_link_libraries(converter icu)
target_link_libraries(converter ${CMAKE_DL_LIBS})
