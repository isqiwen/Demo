cmake_minimum_required(VERSION 3.10)

# set the project name
project(ConanDemo VERSION 1.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -std=c++11 -DHAVE_BLAS=1 -DHAVE_LAPACK=1")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

find_package(LAPACKE REQUIRED)

add_executable(conan_demo src/main.cpp)
target_link_libraries(conan_demo CONAN_PKG::eigen lapacke)
