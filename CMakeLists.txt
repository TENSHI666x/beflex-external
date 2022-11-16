cmake_minimum_required(VERSION 3.5)

project(beflex)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG=1)
endif()

add_executable(beflex
    src/main.cpp
    src/utility/MemoryManager.cpp
    src/sdk/Entity.cpp
    src/features/RadarHack.cpp
)

target_include_directories(beflex PRIVATE ${PROJECT_SOURCE_DIR}/include)