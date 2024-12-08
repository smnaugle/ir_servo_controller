/**
 * Copyright (c) 2021 mjcross
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <cstdlib>
#include <stdio.h>

extern "C" {
#include "nec_receive.h"
}

#include "Servo.h"

// Infrared loopback example ('NEC' format)
//
// Need to connect an IR LED to GPIO 14 via a suitable series resistor
// (e.g. 1.5k) and an active-low IR detector to GPIO 15 (e.g. VS1838b)
//
// Output is sent to stdout

int main() {
    stdio_init_all();

    PIO pio =
        pio0; // choose which PIO block to use (RP2040 has two: pio0 and pio1)
    uint rx_gpio = 20; // choose which GPIO pin is connected to the IR detector

    // configure and enable the state machines
    int rx_sm =
        nec_rx_init(pio, rx_gpio); // uses one state machine and 9 instructions

    if (rx_sm == -1) {
        printf("could not configure PIO\n");
        return -1;
    }

    Servo servo = Servo();
    uint servo_gpio = 16;
    servo.attach(servo_gpio);
    int position = 0;
    servo.write(position);

    // transmit and receive frames
    uint8_t rx_address, rx_data;
    while (true) {
        while (!pio_sm_is_rx_fifo_empty(pio, rx_sm)) {
            uint32_t rx_frame = pio_sm_get(pio, rx_sm);
            if (nec_decode_frame(rx_frame, &rx_address, &rx_data)) {
                printf("received: %02x, %02x\n", rx_address, rx_data);
                if (rx_address == 04) {
                    if (rx_data == 02) {
                        printf("Raising volume.\n");
                        position = servo.read() + 5;
                    }
                    if (rx_data == 03) {
                        printf("Lowering volume.\n");
                        position = servo.read() - 5;
                    }
                }
                if (position > 180) {
                    position = 180;
                }
                if (position < 0) {
                    position = 0;
                }
                servo.write(position);
                printf("Servo is %i", servo.read());
            }
        }
    }
}
