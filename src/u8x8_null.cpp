// u8x8_null.cpp
#include "u8x8.h"

extern "C" uint8_t u8x8_byte_null(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    return 1;
}

extern "C" uint8_t u8x8_gpio_and_delay_null(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    return 1;
}
