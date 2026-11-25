cmake_minimum_required(VERSION 3.21)
project(binscope VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Makes compile_commands.json for editor tooling (clangd etc.)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(binscope)

# Add new .cpp files to this list as you create them.
target_sources(binscope PRIVATE
    src/main.cpp
)

# Headers: put them in include/ and #include "like_this.hpp"
target_include_directories(binscope PRIVATE include)

target_compile_options(binscope PRIVATE -Wall -Wextra -Wpedantic)
