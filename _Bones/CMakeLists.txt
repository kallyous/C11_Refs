cmake_minimum_required(VERSION 3.14)
project(App C)

set(CMAKE_C_STANDARD 11)

include_directories("${PROJECT_SOURCE_DIR}/include")

set(SOURCE_FILES src/main.c src/debug.c src/argdefs.c src/globals.c)

add_executable(app ${SOURCE_FILES})
