#ifndef STTS751_H
#define STTS751_H

#include <Wire.h>

class STTS751 {
  public:
    // Constructor
    STTS751(uint8_t i2cAddress = 0x48);

    // Initialization function
    bool begin();

    // Function to read temperature
    float readTemperature();

    // Function to set configuration register
    void setConfiguration(uint8_t config);

  private:
    uint8_t _i2cAddress;

    // Helper function to read a register
    uint8_t readRegister(uint8_t reg);

    // Helper function to write to a register
    void writeRegister(uint8_t reg, uint8_t value);
};

#endif
