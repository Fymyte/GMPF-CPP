# Setup policy
cmake_policy(SET CMP0048 NEW)
# Set the name of the project
project(GMPF VERSION "")
# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 3.16)

################################
# Gtkmm lib
################################
# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtkmm-3.0 gmodule-2.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
add_definitions(${GTK3_CFLAGS_OTHER})

################################
# Boost lib
################################
## Find boost for logging
#find_package(Boost REQUIRED)
## Setup CMake to use Boost, tell the compiler where to look for headers
## and to the linker where to look for libraries
#include_directories(${Boost_INCLUDE_DIRS})
#link_directories(${Boost_LIBRARY_DIRS})

################################
# JSON Parser
################################
include(FetchContent)

FetchContent_Declare(
        json
        GIT_REPOSITORY  https://github.com/nlohmann/json.git
        GIT_TAG         v3.9.1
)

FetchContent_MakeAvailable(json)

################################
# Setup project
################################
# Add an executable compiled from sources
include_directories(includes)
# Main gmpf target
add_executable(gmpf "")
set_property(TARGET gmpf PROPERTY CXX_STANDARD 20)

# Tests targets
add_executable(unitTest "")
set_property(TARGET unitTest PROPERTY CXX_STANDARD 20)

# Include CMakeLists from subdirectories which may define sources for targets
#include(test/CMakeLists.txt)
#include(src/CMakeLists.txt)

add_subdirectory(src)
add_subdirectory(test)

# Copy required files in the build directory
configure_file(resources/config.json ${CMAKE_BINARY_DIR}/config.json COPYONLY)
configure_file(resources/interface.glade ${CMAKE_BINARY_DIR}/interface.glade COPYONLY)
configure_file(resources/images/GMPF.png ${CMAKE_BINARY_DIR}/images/GMPF.png COPYONLY)
configure_file(resources/themes/main.css ${CMAKE_BINARY_DIR}/themes/main.css COPYONLY)

# Link the target to libraries
target_link_libraries(gmpf ${GTK3_LIBRARIES} ${GTK3_LDFLAGS} nlohmann_json::nlohmann_json ${Boost_LIBRARIES})

################################
# GTest
################################
FetchContent_Declare(
        googletest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         release-1.10.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Now simply link against gtest or gtest_main
target_link_libraries(unitTest gtest_main)
add_test(NAME UnitTests COMMAND unitTest)
