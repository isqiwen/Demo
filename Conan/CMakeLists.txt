cmake_minimum_required(VERSION 3.10)

# set the project name
project(ConanDemo VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(conan_demo src/main.cpp)
target_link_libraries(conan_demo CONAN_PKG::boost)