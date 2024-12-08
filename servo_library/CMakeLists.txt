# build a normal library
#

add_library(servo_library Servo.cpp)

# invoke pio_asm to assemble the PIO state machine programs
#
pico_generate_pio_header(servo_library ${CMAKE_CURRENT_LIST_DIR}/servo.pio)

target_link_libraries(servo_library PRIVATE
        pico_stdlib
        hardware_pio
        )

# add the `binary` directory so that the generated headers are included in the project
#
target_include_directories (servo_library PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
	)

# cmake_minimum_required(VERSION 3.13)
# include(pico_sdk_import.cmake)
# include_directories(/home/sam/projects/pipeco/scratch/servo-new/)
# project(test_project C CXX ASM)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_C_STANDARD 11)
# set(CMAKE_CXX_STANDARD 17)
# pico_sdk_init()
# add_executable(
#     Servo
#     Servo.cpp
#     Servo.h
# )
# pico_generate_pio_header(Servo ${CMAKE_CURRENT_LIST_DIR}/servo.pio)
# pico_enable_stdio_usb(Servo 1)
# pico_enable_stdio_uart(Servo 1)
# pico_add_extra_outputs(Servo)
# target_link_libraries(
#     Servo 
#     pico_stdlib
#     hardware_pio
# )
