cmake_minimum_required(VERSION 3.15)
project(my_cmake_project C)

set(CMAKE_C_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include)

# -------- Firmware Target --------
add_executable(firmware.elf
    src/main.c
    src/math_utils.c
)

# ARM compile options
target_compile_options(firmware.elf PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -ffreestanding
)

# ARM link options
target_link_options(firmware.elf PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -nostdlib
    -nostartfiles
    -Wl,--gc-sections
    -T${CMAKE_SOURCE_DIR}/linker.ld
    -Wl,-Map=${CMAKE_BINARY_DIR}/firmware.map
)

# Generate HEX & BIN
find_program(OBJCOPY arm-none-eabi-objcopy REQUIRED)

add_custom_command(
    TARGET firmware.elf POST_BUILD
    COMMAND ${OBJCOPY} -O ihex firmware.elf firmware.hex
    COMMAND ${OBJCOPY} -O binary firmware.elf firmware.bin
    COMMENT "Generating HEX and BIN"
)

# -------- Test Target (ONLY for host machine) --------
if(NOT CMAKE_C_COMPILER MATCHES "arm-none-eabi")

    add_executable(test_app
        tests/test_math.c
        src/math_utils.c
    )

    enable_testing()
    add_test(NAME RunTests COMMAND test_app)

endif()


