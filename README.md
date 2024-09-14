# toy-robot-challenge

Toy Robot challenge solution written in C++

## System Requirements

- `C++14`
- [`CMake>=3.14`](https://cmake.org/download/)

## Setup and building

1. Configure the build tree

   ```
   cmake -S . -B build
   ```

2. Build the project binaries
   ```
   cmake --build build
   ```

## Testing

### Unit tests

```
# cmd
cd build\Debug
UnitTests.exe

# bash
cd build/Debug
./UnitTests
```

### Using the supplied input files

```
# cmd
> build\Debug\ToyRobot.exe < sample_data.txt > test_output.txt
> fc test_output.txt expected_output.txt
```

The output of `fc` above should be:

```
Comparing files test_output.txt and EXPECTED_OUTPUT.TXT
FC: no differences encountered
```
