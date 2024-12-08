# ir_servo_controller
A small Raspberry Pi Pico program that controls a servo based on inputs from an IR remote control. Very much so a WIP.

## Installation instruction
Installation requires the [pico-sdk](https://github.com/raspberrypi/pico-sdk) and for the `PICO_SDK_PATH` variable to be set. To compile the code, simply run `make` within the root project directory.

## Credits
The servo code is essentially identical to the servo library in the [arduino-pico](https://github.com/earlephilhower/arduino-pico/tree/master/libraries/Servo/src) repo, with some slight modifications to make it compile against only the pico-sdk. The IR reciever library is taken straight from the [pico-examples](https://github.com/raspberrypi/pico-examples/tree/master/pio/ir_nec/nec_receive_library) repo.
