#include "STTS751.h"

// Constructor
STTS751::STTS751(uint8_t i2cAddress) {
  _i2cAddress = i2cAddress;
}

// Initialization function
bool STTS751::begin() {
  Wire.begin();
  
  // Check if the sensor responds by reading a known register (temperature MSB register)
  uint8_t tempMSB = readRegister(0x00);
  if (tempMSB == 0xFF) {
    return false;  // sensor did not respond
  }
  
  return true;
}

// Function to read temperature
float STTS751::readTemperature() {
  uint8_t msb = readRegister(0x00);  // Temperature MSB
  uint8_t lsb = readRegister(0x02);  // Temperature LSB (if needed)
  
  // Combine MSB and LSB for full temperature value
  int16_t temp = (msb << 8) | lsb;
  
  // Convert to Celsius (depends on sensor's resolution)
  float temperature = temp / 256.0;
  return temperature;
}

// Function to set configuration register
void STTS751::setConfiguration(uint8_t config) {
  writeRegister(0x03, config);
}

// Helper function to read a register
uint8_t STTS751::readRegister(uint8_t reg) {
  Wire.beginTransmission(_i2cAddress);
  Wire.write(reg);
  Wire.endTransmission();
  
  Wire.requestFrom(_i2cAddress, (uint8_t)1);
  return Wire.read();
}

// Helper function to write to a register
void STTS751::writeRegister(uint8_t reg, uint8_t value) {
  Wire.beginTransmission(_i2cAddress);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
}
