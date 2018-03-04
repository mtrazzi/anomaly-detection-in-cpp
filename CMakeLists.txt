cmake_minimum_required(VERSION 3.6)   # CMake version check
project(anomaly-detection)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard

set(SOURCE_FILES src/main.cpp src/estimate.cpp src/parser.cpp src/eigen.cpp src/proba.cpp src/anomaly.cpp
  src/threshold.cpp src/print.cpp)            # Add main.cpp file of project root directory as source file

set(Headers header.hpp)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
add_definitions     ( ${EIGEN3_DEFINITIONS} )

include_directories(include)
include_directories(${EIGEN_INCLUDE_DIRS})

find_package(Eigen3 REQUIRED)

INCLUDE_DIRECTORIES ( "${EIGEN3_INCLUDE_DIR}" )

add_executable(threshold ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable
