#include <Wire.h>
#include <STTS751.h>

STTS751 sensor;

void setup() {
  Serial.begin(115200);

  if (!sensor.begin()) {
    Serial.println("Failed to initialize STTS751 sensor!");
    while (1);
  }
  
  Serial.println("STTS751 sensor initialized.");
}

void loop() {
  float temperature = sensor.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  delay(1000);
}
