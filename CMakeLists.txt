cmake_minimum_required(VERSION 3.0)
project(converter)
set(CMAKE_BINARY_DIR "/home/cricket/cpp/icu_converter")

# add_definitions(-DUDATA_DEBUG=1)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})


if (DEFINED ICU_ROOT_DIR)
    set(ICU_INCLUDE_DIR "${ICU_ROOT_DIR}/common")
endif (DEFINED ICU_ROOT_DIR)

find_package(Threads)
find_package(ICU COMPONENTS i18n data uc REQUIRED )

include_directories(BEFORE "${ICU_INCLUDE_DIR}")

add_executable(converter converter.cpp)
target_link_libraries(converter ${CMAKE_DL_LIBS})
target_link_libraries(converter ${CMAKE_THREAD_LIBS_INIT} )
target_link_libraries(converter "${ICU_ROOT_DIR}/lib/libicudata.so")
target_link_libraries(converter "${ICU_ROOT_DIR}/lib/libicui18n.so")
target_link_libraries(converter "${ICU_ROOT_DIR}/lib/libicuuc.so")
