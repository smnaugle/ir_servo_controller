cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(ir_servo_controller C CXX ASM)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_subdirectory(nec_receive_library)
add_subdirectory(servo_library)
add_executable (ir_servo_controller ir_servo_controller.cc)

# link the executable using the IR receive library
target_link_libraries(ir_servo_controller LINK_PUBLIC
  pico_stdlib
  hardware_pio
  nec_receive_library
  servo_library
  )

pico_add_extra_outputs(ir_servo_controller)
pico_enable_stdio_usb(ir_servo_controller 1)
pico_enable_stdio_uart(ir_servo_controller 1)
