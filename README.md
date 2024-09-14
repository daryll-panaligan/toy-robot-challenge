# toy-robot-challenge

Toy Robot challenge solution written in C++. Unit tests created with https://github.com/google/googletest

## System Requirements

- `C++14`
- [`CMake>=3.14`](https://cmake.org/download/)

## Setup and building

1. Generate the build system

   ```
   cmake -S . -B build
   ```

2. Build the project binaries
   ```
   cmake --build build
   ```

# Usage
Run the `ToyRobot` CLI
```
# cmd
cd build\Debug
ToyRobot.exe

# bash
cd build/Debug
./ToyRobot
```

## Commands
_All commands are __CASE SENSITIVE___. Invalid commands are handled silently.

`PLACE x,y,direction`
- Places the robot on a 5x5 table on the specified coordinate at `x, y` facing `direction`.
  - `direction` can be `NORTH`, `EAST`, `SOUTH`, `WEST`
  - `0, 0` is the origin at the SOUTHWEST corner of the table
  - `x, y` values outside of the table will be ignored

`MOVE`
- Move the robot one unit in the direction of `direction` except if it will cause the robot to be out of bounds.

`LEFT` / `RIGHT`
- Rotate the robot 90 degrees in the specified direction

`REPORT`
- Report the current `x,y,direction` values of the robot

# Testing

## Unit tests

```
# cmd
cd build\Debug
UnitTests.exe

# bash
cd build/Debug
./UnitTests
```

## Using the supplied input files

```
# cmd
build\Debug\ToyRobot.exe < sample_data.txt > test_output.txt
fc test_output.txt expected_output.txt
```

The output of `fc` above should be:

```
Comparing files test_output.txt and EXPECTED_OUTPUT.TXT
FC: no differences encountered
```
