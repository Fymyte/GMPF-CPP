# Set the name and the supported language of the project
PROJECT(GMPF)
# Set the minimum version of cmake required to build this project
CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

# Add an executable compiled from hello.c
INCLUDE_DIRECTORIES("includes")
ADD_EXECUTABLE(gmpf "")
ADD_SUBDIRECTORY(src)

INCLUDE(src/CMakeLists.txt)

# Link the target to the GTK+ libraries
TARGET_LINK_LIBRARIES(gmpf ${GTK3_LIBRARIES})