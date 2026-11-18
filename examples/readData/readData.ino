/*
  Read AHT30 Sensor value
*/
#include <Wire.h>
#include <Bonezegei_AHT30.h>

// Initialize AHT30 with default I2C address (0x38)
Bonezegei_AHT30 aht30(0x38);

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!aht30.begin()) {
    Serial.println("Could not find a valid AHT30 sensor, check wiring!");
    while (1);
  }

  Serial.println("AHT30 Sensor Initialized!");
}

void loop() {
  if (aht30.read()) {
    Serial.print("Temperature: ");
    Serial.print(aht30.getTemperature());
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(aht30.getHumidity());
    Serial.println(" %");

    Serial.println("------------------------------------");
  } else {
    Serial.println("Failed to read from AHT30 sensor!");
  }

  delay(2000);
}