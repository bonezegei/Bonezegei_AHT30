/*
  Bonezegei_AHT30.h - Arduino Library for AHT30 Sensor
  Author: Jofel Batutay (Bonezegei)
  Date: November 18, 2026
*/

#ifndef BONEZEGEI_AHT30_H
#define BONEZEGEI_AHT30_H

#include <Arduino.h>
#include <Wire.h>

#define AHT30_I2C_ADDR 0x38

#define AHT30_CMD_INITIALIZE 0xBE
#define AHT30_CMD_MEASURE    0xAC
#define AHT30_CMD_SOFT_RESET 0xBA

class Bonezegei_AHT30 {
public:
  Bonezegei_AHT30(uint8_t addr = AHT30_I2C_ADDR);
  
  bool begin(TwoWire &wirePort = Wire);
  bool read();
  
  float getTemperature();  // Returns Temperature in Celsius
  float getHumidity();     // Returns Relative Humidity in %

private:
  uint8_t _addr;
  TwoWire *_wire;

  float _temperature;
  float _humidity;

  uint8_t readStatus();
};

#endif