cmake_minimum_required(VERSION 3.10)

# set the project name
project(CPPDemo VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# import conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# add subdirectory
add_subdirectory(nlohmann_json_demo)
add_subdirectory(cpp_grammar_demo)
