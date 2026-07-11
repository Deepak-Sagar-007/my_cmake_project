cmake_minimum_required(VERSION 3.10)

project(CProject C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

# Main executable
add_executable(my_app src/main.c)

# Test executable
add_executable(test_app tests/test_math.c)

enable_testing()
add_test(NAME RunTests COMMAND test_app)