# Set the name of the project
project(GMPF)
# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 3.16)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtkmm-3.0 gmodule-2.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
add_definitions(${GTK3_CFLAGS_OTHER})

# Add an executable compiled from sources
include_directories("includes")
add_executable(gmpf "")
add_subdirectory(src)
set_property(TARGET gmpf PROPERTY CXX_STANDARD 20)

# Recursively include files located in src directory as files for gmpf target
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(src/CMakeLists.txt)
# Copy required files in the build directory
configure_file(resources/interface.glade ${CMAKE_BINARY_DIR}/interface.glade COPYONLY)
configure_file(resources/images/GMPF.png ${CMAKE_BINARY_DIR}/images/GMPF.png COPYONLY)
configure_file(resources/themes/main.css ${CMAKE_BINARY_DIR}/themes/main.css COPYONLY)

# Link the target to the GTK+ libraries
target_link_libraries(gmpf ${GTK3_LIBRARIES} ${GTK3_LDFLAGS})