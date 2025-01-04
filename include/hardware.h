#include <OpenKNXHardware.h>

#ifdef BOARD_AB_SMARTHOUSE_BI_REG6_16CH
    #define DEVICE_ID "AB-BIN-16CH"
    #define HARDWARE_NAME "AB-BIN-16CH"
    #define DEVICE_NAME "AB-SmartHouse Binary Input 16x, 6 TE"

    #define INFO_LED_PIN 11
    #define INFO_LED_PIN_ACTIVE_ON HIGH
    #define PROG_LED_PIN 10
    #define PROG_LED_PIN_ACTIVE_ON HIGH
    #define PROG_BUTTON_PIN 9
    #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING

    #define KNX_UART_TX_PIN 12
    #define KNX_UART_RX_PIN 13
    #define SAVE_INTERRUPT_PIN 0

    #define OPENKNX_BIN_OUT_TCA_WIRE Wire1
    #define OPENKNX_BIN_OUT_TCA_ADDR 0x20
    #define OPENKNX_BIN_OUT_TCA_SDA 6
    #define OPENKNX_BIN_OUT_TCA_SCL 7

    #define OPENKNX_BI_GPIO_PINS 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 14, 15, 16, 17
    #define OPENKNX_BI_GPIO_COUNT 16
    #define OPENKNX_BI_ONLEVEL LOW
#endif
