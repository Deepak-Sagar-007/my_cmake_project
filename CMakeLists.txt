cmake_minimum_required(VERSION 3.10)

project(my_cmake_project C)

set(CMAKE_C_STANDARD 11)

# Include headers

include_directories(include)

# -------------------------

# Main Application

# -------------------------

add_executable(my_app
src/main.c
src/math_utils.c
)

# -------------------------

# Test Application

# -------------------------

add_executable(test_app
tests/test_math.c
src/math_utils.c
)

# -------------------------

# Enable Testing

# -------------------------

enable_testing()

add_test(NAME RunTests COMMAND test_app)
