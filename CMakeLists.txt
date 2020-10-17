if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
    message("No build type specified, default to release")
else()
    message("Cmake build type: " ${CMAKE_BUILD_TYPE})
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Setup policy
cmake_policy(SET CMP0048 NEW)
# Set the name of the project
project(GMPF VERSION "0.0.1")
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
# Boost options
################################
# Find boost library
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS system program_options)
set(Boost_LIBS Boost::system Boost::program_options)

################################
# Setup project
################################
# Print debug info only if compilation is in debug
# Add an executable compiled from sources
include_directories(includes)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_DEBUG 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Main gmpf target
add_executable(gmpf "")
# Tests targets
add_executable(unitTest "")

# Include CMakeLists from subdirectories which may define sources for targets
add_subdirectory(src)
add_subdirectory(test)

# Copy required files in the build directory
configure_file(resources/interface.glade ${CMAKE_BINARY_DIR}/interface.glade COPYONLY)
configure_file(resources/images/GMPF.png ${CMAKE_BINARY_DIR}/images/GMPF.png COPYONLY)
configure_file(resources/themes/main.css ${CMAKE_BINARY_DIR}/themes/main.css COPYONLY)
configure_file(resources/gmpf.conf ${CMAKE_BINARY_DIR}/gmpf.conf COPYONLY)

# Define macro for project information
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPROJECT_VERSION='\"${CMAKE_PROJECT_VERSION}\"'")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPROJECT_NAME='\"${CMAKE_PROJECT_NAME}\"'")

# Define macro for debug logs
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DGMPF_DEBUG_LOG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D__FILENAME__='\"$(subst ${CMAKE_SOURCE_DIR}/,,$(abspath $<))\"'")
# Link the target to libraries
target_link_libraries(gmpf ${Boost_LIBS} ${GTK3_LIBRARIES} ${GTK3_LDFLAGS})

################################
# GTest
################################
message("\nDownloading gtest dependency, this may take some time...\n")
include(FetchContent)
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

################################
# Doxygen
################################
# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_SOURCE_DIR}/docs/)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # option ALL allows to build the docs together with the application
    add_custom_target( Doc ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)