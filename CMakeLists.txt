cmake_policy(SET CMP0048 NEW)
# Set the name of the project
project(GMPF VERSION "")
# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 3.16)

set_property(GLOBAL PROPERTY CXX_STANDARD 20)

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
include_directories(includes)
add_executable(gmpf "")

# Tests targets
add_executable(unitTest "")

# Include CMake from subdirectories which may define sources for targets
include(test/CMakeLists.txt)
# Recursively include files located in src directory as files for gmpf target
include(src/CMakeLists.txt)

add_subdirectory(src)

# Copy required files in the build directory
configure_file(resources/interface.glade ${CMAKE_BINARY_DIR}/interface.glade COPYONLY)
configure_file(resources/images/GMPF.png ${CMAKE_BINARY_DIR}/images/GMPF.png COPYONLY)
configure_file(resources/themes/main.css ${CMAKE_BINARY_DIR}/themes/main.css COPYONLY)

# Link the target to the GTK+ libraries
target_link_libraries(gmpf ${GTK3_LIBRARIES} ${GTK3_LDFLAGS})


# ---------------------------- GOOGLE TEST ---------------------------- #
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# Now simply link against gtest or gtest_main
target_link_libraries(unitTest gtest_main)
add_test(NAME position COMMAND unitTest)
