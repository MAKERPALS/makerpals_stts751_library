# STTS751 Arduino Library

This is an Arduino library for the STTS751 Temperature Sensor. It communicates using I2C and provides an easy-to-use interface for reading temperature values.

## Features:
- Read temperature in Celsius
- Set sensor configuration
- Example sketch for testing

## Installation

1. Download the repository as a ZIP file or clone it.
2. Copy the `STTS751` folder into your Arduino libraries directory (`Documents/Arduino/libraries`).
3. Restart the Arduino IDE.

## Usage Example

```cpp
#include <STTS751.h>

STTS751 sensor;

void setup() {
  Serial.begin(115200);

  if (!sensor.begin()) {
    Serial.println("Failed to initialize STTS751 sensor!");
    while (1);
  }
}

void loop() {
  float temperature = sensor.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  delay(1000);
}
