cmake_minimum_required(VERSION 3.25.0)
project(SamsCalc)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "-Wall -Wextra")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(hdr ${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})

add_definitions(${GTK4_CFLAGS_OTHER})

add_executable(samscalc "")
include(cmake/sourcelist.cmake)
target_link_libraries(samscalc m ${GTK4_LIBRARIES})
