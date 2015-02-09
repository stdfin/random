cmake_minimum_required(VERSION 2.8)
enable_testing()

project(stdfin_examples)

# - Use C++11 standard
#
# Author:
#   Kevin M. Godby <kevin@godby.org>
#

# Note that Microsoft Visual C++ compiler enables C++11 by default

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR CMAKE_COMPILER_IS_GNUCXX)
    include(CheckCXXCompilerFlag)
    check_cxx_compiler_flag(--std=c++11 SUPPORTS_STD_CXX11)
    check_cxx_compiler_flag(--std=c++0x SUPPORTS_STD_CXX01)
    if(SUPPORTS_STD_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --std=c++11")
    elseif(SUPPORTS_STD_CXX01)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++0x")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --std=c++0x")
    else()
        message(ERROR "Compiler does not support --std=c++11 or --std=c++0x.")
    endif()
endif()


include_directories(../include)
include_directories(include)

# list of examples:
add_executable(test_non_central_chi_squared_distribution test_non_central_chi_squared_distribution.cpp)

add_test(test_non_central_chi_squared_distribution test_non_central_chi_squared_distribution)
