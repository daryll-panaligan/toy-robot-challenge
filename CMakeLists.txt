# Setup project

cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(toy-robot-challenge)

# Compile main application

include_directories(lib)

set(SOURCES
    src/main.cpp
    src/robot.cpp
    src/utils.cpp
)

set(HEADERS
    lib/robot.h
    lib/utils.h
)

add_executable(ToyRobot ${SOURCES} ${HEADERS})

target_include_directories(ToyRobot
    PRIVATE
        ${PROJECT_SOURCE_DIR}/lib
)

# Compile unit tests

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(TESTS
    tests/tests.cpp
)

add_executable(UnitTests ${TESTS})
add_library(ToyRobotLib ${SOURCES} ${HEADERS})
target_link_libraries(UnitTests gtest_main gmock_main ToyRobotLib)
include(GoogleTest)
gtest_discover_tests(UnitTests)
