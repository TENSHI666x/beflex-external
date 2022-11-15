cmake_minimum_required(VERSION 3.2)

project(beflex)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG=1)
endif()

add_executable(beflex
    main.cpp
    csgo.hpp
    utility/MemoryManager.h
    utility/MemoryManager.cpp
)