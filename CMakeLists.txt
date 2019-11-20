#/* CMakeLists.txt
#   This is an alternative way to compile the project in addition to XCode or
#   the makefile. It is also useful for the CLion IDE and for Conan.
#*/

# Setup
# ...The minimum version of CMake that we want collaborators to be using
cmake_minimum_required(VERSION 3.15)

# Project name
project(cpptesting)

# Variables
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER g++)
set(WARN_DEFAULTS "-Wall -Wextra -Wpedantic")  # TODO
set(SRC_DIR src/)
list(APPEND includes
    "/usr/local/include"
    "/usr/include")
list(APPEND relativeIncludes
    "env/include")

# Build: Main
# -Source files to compile from
file(GLOB SOURCES "${SRC_DIR}*.cpp")
# -Binaries to compile to
add_executable(testing ${SOURCES})
# -Includes
target_include_directories(testing PUBLIC
    "$<BUILD_INTERFACE:${includes}>"
    "$<INSTALL_INTERFACE:${relativeIncludes}>")
# -Links
# -- n/a

# Report
message(\nBuild info:\n
    - CMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}\n
    - CMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}\n
    - CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}\n
    - SRC_DIR=${SRC_DIR}\n
    - includes=${includes}\n)
