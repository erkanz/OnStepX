// Classic ESP32-WROOM, dedicated AXIS3 antenna rotator (NEMA17 + TMC2209).
// Hardware: VIO->3V3, VM->motor 12V, grounds common.
// Single-wire PDN_UART <- GPIO32 TX through 1 kOhm; GPIO16 RX directly.
// MS1 and MS2 grounded for UART address 0.
// STEP=26, DIR=25, EN=33 active low.
// GPIO21/GPIO22 reserved for OLED (not yet managed by firmware).
#pragma once
#if defined(ESP32)
  #if SERIAL_A_BAUD_DEFAULT != OFF
    #define SERIAL_A Serial
  #endif
  #if defined(STEP_DIR_TMC_UART_PRESENT) || defined(SERVO_TMC2209_PRESENT)
    #define SERIAL_TMC_HARDWARE_UART
    #define SERIAL_TMC Serial1
    #define SERIAL_TMC_BAUD 115200
    #define SERIAL_TMC_RX 16
    #define SERIAL_TMC_TX 32
    #define SERIAL_TMC_ADDRESS_MAP(x) (0)
  #endif
  #define I2C_SDA_PIN 21
  #define I2C_SCL_PIN 22
  #define AXIS3_ENABLE_PIN 33
  #define AXIS3_STEP_PIN 26
  #define AXIS3_DIR_PIN 25
  #define AXIS3_M0_PIN OFF
  #define AXIS3_M1_PIN OFF
  #define AXIS3_M2_PIN OFF
  #define AXIS3_M3_PIN OFF
#else
  #error "ESP32_TMC2209_ROTOR requires an ESP32-WROOM"
#endif
