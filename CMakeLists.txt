cmake_minimum_required(VERSION 3.14)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(toy-robot-challenge)

# add header files in the lib
include_directories(lib)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp
)

# Add an executable with the above sources
add_executable(ToyRobot ${SOURCES})

target_include_directories(ToyRobot
    PRIVATE
        ${PROJECT_SOURCE_DIR}/lib
)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
# Create a sources variable with a link to all cpp files to compile
enable_testing()

set(TESTS
    tests/tests.cpp
)

add_executable(UnitTests ${TESTS})
target_link_libraries(UnitTests GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(UnitTests)
