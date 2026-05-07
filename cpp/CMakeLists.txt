cmake_minimum_required(VERSION 3.14)
project(Bouffalant LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# Library
file(GLOB BOUFFALANT_SOURCES "src/*/*.cpp")
add_library(bouffalant ${BOUFFALANT_SOURCES})
target_include_directories(bouffalant PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Test executable
file(GLOB BOUFFALANT_TESTS "test/*/*.cpp")
add_executable(bouffalant_tests ${BOUFFALANT_TESTS})
target_link_libraries(bouffalant_tests PRIVATE bouffalant gtest_main)
gtest_discover_tests(bouffalant_tests)
